/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:55:54 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 23:10:30 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <limits.h>

// Was getting a black screen after adding diffuse, bug caused by not
// initializing record hit to false.

int	get_hit_from_objects(t_ray r, t_list *objects, t_hit_rec *rec)
{
	t_hit_rec	tmp_rec;
	double		closest;

	closest = __DBL_MAX__;
	rec->hit = 0;
	while (objects)
	{
		tmp_rec = run_hit_funcs(r, 0.001, closest, (t_object *)objects->content);
		if (tmp_rec.hit == 1)
		{
			closest = tmp_rec.t;
			*rec = tmp_rec;
		}
		objects = objects->next;
	}
	return (rec->hit);
}

t_vec	get_target(t_hit_rec rec)
{
	// rand_d(rec.normal.e1 + 1);
	// show_vec(v_sum(rec.p, v_sum(rec.normal, random_in_unit_sphere())));
	return (v_sum(rec.p, v_sum(rec.normal, random_in_unit_sphere())));
}

t_vec	calc_color(t_ray ray, t_list *objects, int depth)
{
	t_hit_rec	rec;
	t_vec		unit_dir;
	double		t;
	t_ray		new_ray;

	if (depth <= 0)
		return ((t_vec){0, 0, 0, 0});
	if (get_hit_from_objects(ray, objects, &rec) == 1)
	{
		new_ray.origin = rec.p;
		new_ray.dir = v_subtr(get_target(rec), rec.p);
		return (v_multi_d(calc_color(new_ray, objects, depth - 1), 0.5));
	}
	else
	{
		unit_dir = unit_vec(ray.dir);
		t = 0.5 * (get(&unit_dir, y) + 1.0);
		return (v_sum(v_multi_d((t_vec){0.3, 0.5, 1.0, 0}, (1.0 - t)),
			v_multi_d((t_vec){1.0, 1.0, 1.0, 0}, t)));
	}
}


t_ray	camera_get_ray(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.dir = v_subtr(v_sum(cam->lower_left_corner, v_sum(v_multi_d
					(cam->horizontal, u), v_multi_d(cam->vertical, v))),
			cam->origin);
	return (ray);
}

t_vec	anti_alias_color(int i, int j, t_data *data, int ns)
{
	t_ray	ray;
	t_vec	color;
	int		c;

	c = -1;
	color = (t_vec){0, 0, 0, 0};
	while (++c < ns)
	{
		ray = camera_get_ray(
				&data->scene.camera,
				(double)(i + rand_d(0)) / data->w,
				(double)(j + rand_d(0)) / data->h);
		color = v_sum(color, calc_color(ray, data->objects, ns));
	}
	return (color);
}

/**
 * for each pixel,
 * compute the primary ray,
 * check for intersections, get the closest one,
 * calc shadow ray (not yet)
 * render
 *
*/
void	render_image(t_data *data)
{
	int		i;
	int		j;
	t_vec	color;
	int		ns;

	ns = 50;
	data->scene.camera.lower_left_corner = new_vect(-2.0, -1.0, -1.0);
	data->scene.camera.horizontal = new_vect(4.0, 0.0, 0.0);
	data->scene.camera.vertical = new_vect(0.0, 2.0, 0.0);
	j = data->h;
	ft_putstr_fd("> Starting ray trace......\n", 1);
	while (--j >= 0)
	{
		i = -1;
		while (++i < data->w)
		{
			color = anti_alias_color(i, j, data, ns);
			// show_vec(color);
			color = v_div_d(color, ns);
			put_pixel(&data->img, i, j, create_trgb_vec(&color));
		}
	}
}
