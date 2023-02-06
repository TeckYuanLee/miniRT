/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:48:03 by telee             #+#    #+#             */
/*   Updated: 2023/02/06 12:02:27 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Convert light to color
 *
 * @param color
 * @param rgb
 * @return int
 */
int	color_x_light(int color, t_vec rgb)
{
	unsigned int	mask;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	mask = 255 << 16;
	r = rgb.e1 * ((color & mask) >> 16);
	mask >>= 8;
	g = rgb.e2 * ((color & mask) >> 8);
	mask >>= 8;
	b = rgb.e3 * (color & mask);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return ((r << 16) | (g << 8) | b);
}

/**
 * @brief Check for light intersecrion
 *
 * @param o
 * @param d
 * @param lst
 * @return int
 */
int	light_itsxn(t_vec o, t_vec d, t_list *lst)
{
	double		dist;
	t_object	*obj;

	dist = 0;
	while (lst)
	{
		obj = lst->content;
		if (obj->id == sp)
			dist = solve_sp(o, d, obj);
		else if (obj->id == pl)
			dist = solve_pl(o, d, obj->obj.pl.coor, obj->normal);
		else if (obj->id == cy)
			dist = solve_cy(o, d, obj);
		if (dist > 0.00001 && dist < 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/**
 * @brief Modifies the elements of the "rgb" array by adding to them
 * a coefficient multiplied by the
 * individual color channels of the "color" integer
 *
 * @param rgb
 * @param coef
 * @param color
 */
t_vec	multiplier(t_vec rgb, double coef, int color)
{
	unsigned int	mask;

	mask = 255 << 16;
	rgb.e1 += coef * ((color & mask) >> 16) / 255;
	mask >>= 8;
	rgb.e2 += coef * ((color & mask) >> 8) / 255;
	mask >>= 8;
	rgb.e3 += coef * (color & mask) / 255;
	return (rgb);
}

/**
 * @brief calculate the final color of a pixel by taking into account
 * the lighting of the scene, the color of the object at that point,
 * and the object's surface normal
 *  vcos(itsxn->normal, direction): amt of light that reaches itsxn pt
 *
 * @param itsxn
 * @param lights
 * @param ambient
 * @param lst
 */
void	calc_light(
	t_itsxn *itsxn, t_list *lights, t_ambient ambient, t_list *lst)
{
	double		light_val;
	t_vec		rgb;
	t_vec		dir;
	t_light		*light_obj;

	light_val = 0.0;
	rgb = multiplier((t_vec){0, 0, 0, 0}, ambient.ratio, ambient.color);
	while (lights)
	{
		light_obj = (t_light *)lights->content;
		dir = v_subtr(light_obj->coor, itsxn->point);
		if (light_itsxn(itsxn->point, dir, lst) && dot(itsxn->normal, dir) > 0)
		{
			light_val = light_obj->ratio * v_cos(itsxn->normal, dir);
			rgb = multiplier(rgb, light_val, light_obj->color);
		}
		lights = lights->next;
	}
	itsxn->color = color_x_light(itsxn->color, rgb);
}
