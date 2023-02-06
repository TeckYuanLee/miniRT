/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:22:20 by telee             #+#    #+#             */
/*   Updated: 2023/02/06 11:19:05 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Calculate the surface normal at the point of intersection,
 * taking into account the type of object and
 * the incoming direction of the ray.
 * This information is used to compute the lighting and shading
 * of the object in the scene.
 *
 * @param p point at parameter
 * @param d	ray direction
 * @param normal the normal to set value
 * @param l	the closest object that ray intersects
 */
static void	calc_normal(t_vec p, t_vec d, t_vec *normal, t_object *l)
{
	if (l->id == sp)
	{
		*normal = normalize(v_subtr(p, l->obj.sp.center));
		if (v_cos(d, *normal) > 0)
			*normal = v_multi_d(*normal, -1);
	}
	else if (v_cos(d, l->normal) > 0)
		*normal = v_multi_d(l->normal, -1);
	else
		*normal = l->normal;
}

/**
 * @brief Trace a ray from origin to direction in the scene and
 * return color of the pixel that the ray intersects with the closest object
 *
 * @param d
 * @param data
 * @return int the color value
 */
int	trace_ray(t_ray *ray, t_data *data)
{
	t_itsxn		itsxn;
	t_object	closest_obj;
	double		closest_itsxn;

	closest_obj.id = -1;
	closest_itsxn = INFINITY;
	ray_itsxn(ray, data->objects, &closest_obj, &closest_itsxn);
	itsxn.point = v_sum(ray->origin, v_multi_d(ray->dir, closest_itsxn));
	calc_normal(itsxn.point, ray->dir, &(itsxn.normal), &closest_obj);
	if (closest_obj.id == -1)
		itsxn.color = data->scene.background;
	else
		itsxn.color = closest_obj.color;
	calc_light(&itsxn, data->scene.lights, data->scene.ambient, data->objects);
	return (itsxn.color);
}
