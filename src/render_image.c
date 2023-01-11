/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:55:54 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 10:21:41 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_vec	calc_color(t_ray ray)
{
	t_vec	unit_dir;
	t_vec	N;
	double	t;


	t = hit_sphere(new_vect(0, 0, -1), 0.5, ray);
	if (t > 0)
	{
		N = unit_vec(v_subtr(point_at_parameter(ray, t), new_vect(0, 0, -1)));
		return (v_multi_d(
				new_vect(get(&N, x) + 1, get(&N, y) + 1, get(&N, z) + 1), 0.5));
	}
	unit_dir = unit_vec(ray.dir);
	t = 0.5 * (get(&unit_dir, y) + 1.0);
	return (v_sum(v_multi_d(new_vect(0.3, 0.5, 1.0), (1.0 - t)),
			v_multi_d(new_vect(1.0, 1.0, 1.0), t)));
}

/**
 * for each pixel,
 * compute the primary ray,
 * check for intersections, get the closest one,
 * calc shadow ray (not yet)
 * render
 *
*/
void	render_image(t_data *data, t_object *objects)
{
	(void) objects;
	t_ray		ray;
	t_vec	lower_left_corner;
	t_vec	hori;
	t_vec	vert;
	int			i;
	int			j;
	double		u;
	double		v;
	t_vec	color;

	lower_left_corner = new_vect(-2.0, -1.0, -1.0);
	hori = new_vect(4.0, 0.0, 0.0);
	vert = new_vect(0.0, 2.0, 0.0);
	j = data->h;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data->w)
		{
			u = (double)i / data->w;
			v = (double)j / data->h;
			ray.origin = new_vect(0.0, 0.0, 0.0);
			ray.dir = v_sum(lower_left_corner,
					v_sum(v_multi_d(hori, u), v_multi_d(vert, v)));
			color = calc_color(ray);
			put_pixel(data, i, j, create_trgb_vec(&color));
		}
	}
}
