/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:55:54 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 16:10:14 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <limits.h>

int	get_hit_from_objects(t_ray r, t_list *objects, t_hit_rec *rec)
{
	t_hit_rec	tmp_rec;
	double		closest;

	closest = __DBL_MAX__;
	while (objects)
	{
		tmp_rec = run_hit_funcs(r, 0.0, closest, (t_object *)objects->content);
		if (tmp_rec.hit == 1)
		{
			closest = tmp_rec.t;
			*rec = tmp_rec;
		}
		objects = objects->next;
	}
	return (rec->hit);
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
		new_ray.dir = v_subtr(v_sum(rec.p, v_sum(rec.normal,
						random_in_unit_sphere(rec.p))), rec.p);
		new_ray.origin = rec.p;
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

/**
 * for each pixel,
 * compute the primary ray,
 * check for intersections, get the closest one,
 * calc shadow ray (not yet)
 * render
 *
*/
void	render_image(t_data *data, t_scene *scene, t_list *objects)
{
	t_ray	ray;
	int		i;
	int		j;
	t_vec	color;

	(void) objects;
	scene->camera.lower_left_corner = new_vect(-2.0, -1.0, -1.0);
	scene->camera.horizontal = new_vect(4.0, 0.0, 0.0);
	scene->camera.vertical = new_vect(0.0, 2.0, 0.0);
	j = data->h;
	ft_putstr_fd("> Starting ray trace......\n", 1);
	while (--j >= 0)
	{
		i = -1;
		while (++i < data->w)
		{
			printf("> Tracing x:%d, y:%d\n", i, j);
			ray = camera_get_ray(
					&scene->camera, (double)i / data->w, (double)j / data->h);
			color = calc_color(ray, objects, 50);
			put_pixel(&data->img, i, j, create_trgb_vec(&color));
		}
	}
}
