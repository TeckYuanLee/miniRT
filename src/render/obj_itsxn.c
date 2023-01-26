/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_itsxn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:14:38 by telee             #+#    #+#             */
/*   Updated: 2023/01/20 15:37:35 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	solve_pl(t_vec o, t_vec d, t_vec c, t_vec nv)
{
 	double  x;
	double  denom;

 	denom = dot(nv, d);
	if (denom == 0)
		return (INFINITY);
 	x = (dot(nv, v_subtr(c, o))) / denom;
	if (x > 0)
		return (x);
	return (INFINITY);
}

/**
 * @brief The solution for sphere object.
 *
 * @param o ray origin
 * @param d ray direction
 * @param lst the intersetcted object
 * @return the distance as double
 */
double	solve_sp(t_vec o, t_vec d, t_object *lst)
{
	double	disc;
	double	x[2];
	double	k[3];
	t_vec	c;

	x[0] = INFINITY;
	x[1] = INFINITY;
	c = v_subtr(o, lst->obj.sp.center);
	k[0] = dot(d, d);
	k[1] = 2 * dot(d, c);
	k[2] = dot(c, c) - lst->obj.sp.radius * lst->obj.sp.radius;
	disc = k[1] * k[1] - (4 * k[0] * k[2]);
	if (disc >= 0)
	{
		x[0] = (-k[1] + sqrt(disc)) / (2 * k[0]);
		x[1] = (-k[1] - sqrt(disc)) / (2 * k[0]);
	}
	if (x[0] > 0.00001 && x[0] < INFINITY && x[0] < x[1])
		return (x[0]);
	if (x[1] > 0.00001 && x[1] < INFINITY && x[1] < x[0])
		return (x[1]);
	return (INFINITY);
}

/**
 * @brief Go through the list of objects and check for intersection. Tracks the
 * closest intersection and the closest object.
 *
 * @param d ray direction
 * @param data data struct that holds everything
 * @param closest_obj object pointer to set
 * @param closest_itsxn itsxn pointer to set
 */
void	ray_itsxn(
	t_vec d, t_data data, t_object *closest_obj, double *closest_itsxn)
{
	double	dist;

	dist = 0;
	while (data.objects)
	{
		if (((t_object *)(data.objects->content))->id == sp)
			dist = solve_sp(data.scene.camera.origin,
					d, (t_object *)data.objects->content);
		else if (((t_object *)(data.objects->content))->id == pl)
			dist = solve_pl(data.scene.camera.origin, d, ((t_object *)data.objects->content)->obj.pl.coor, ((t_object *)data.objects->content)->normal);
		else if (((t_object *)(data.objects->content))->id == cy)
			dist = solve_cy(data.scene.camera.origin,
					d, (t_object *)data.objects->content);
		if (dist > 0.00001 && dist < *closest_itsxn)
		{
			*closest_obj = *((t_object *)(data.objects->content));
			*closest_itsxn = dist;
		}
		data.objects = data.objects->next;
	}
}
