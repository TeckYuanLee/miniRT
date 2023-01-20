#include "minirt.h"

/**
 * @brief Convert light to color
 *
 * @param color
 * @param rgb
 * @return int
 */
int	color_x_light(int color, double rgb[3])
{
	unsigned int	mask;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	mask = 255 << 16;
	r = rgb[0] * ((color & mask) >> 16);
	mask >>= 8;
	g = rgb[1] * ((color & mask) >> 8);
	mask >>= 8;
	b = rgb[2] * (color & mask);
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
	double	dist;

	dist = 0;
	while (lst)
	{
		if (((t_object *)lst->content)->id == sp)
			dist = solve_sp(o, d, (t_object *)lst->content);
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
void	multiplier(double (*rgb)[3], double coef, int color)
{
	unsigned int	mask;

	mask = 255 << 16;
	(*rgb)[0] += coef * ((color & mask) >> 16) / 255;
	mask >>= 8;
	(*rgb)[1] += coef * ((color & mask) >> 8) / 255;
	mask >>= 8;
	(*rgb)[2] += coef * (color & mask) / 255;
}

//
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
	double		rgb[3];
	t_vec		dir;
	t_light		*light_obj;

	light_val = 0.0;
	ft_memset(rgb, 0, 3 * sizeof(double));
	multiplier(&rgb, ambient.ratio, ambient.color);
	while (lights)
	{
		light_obj = (t_light *)lights->content;
		dir = v_subtr(light_obj->coor, itsxn->point);
		if (light_itsxn(itsxn->point, dir, lst) && dot(itsxn->normal, dir) > 0)
		{
			light_val = light_obj->ratio * v_cos(itsxn->normal, dir);
			multiplier(&rgb, light_val, light_obj->color);
		}
		lights = lights->next;
	}
	itsxn->color = color_x_light(itsxn->color, rgb);
}
