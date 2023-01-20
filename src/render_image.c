/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:55:54 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 15:37:10 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <limits.h>

int	get_hit_from_objects(t_ray *r, t_list *objects, t_hit_rec *rec)
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

t_vec	calc_color(t_ray *ray, t_list *objects)
{
	t_hit_rec	rec;
	t_vec		unit_dir;
	double		t;

	if (get_hit_from_objects(ray, objects, &rec) == 1)
	{
		return (v_multi_d((t_vec){get(&rec.normal, x) + 1,
				get(&rec.normal, y) + 1, get(&rec.normal, z) + 1, 0}, 0.5));
	}
	else
	{
		unit_dir = unit_vec(ray->dir);
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
	scene->camera.lower_left_corner = (t_vec){-2.0, -1.0, -1.0, 0.0};
	scene->camera.horizontal = (t_vec){4.0, 0.0, 0.0, 0};
	scene->camera.vertical = (t_vec){0.0, 2.0, 0.0, 0};
	j = scene->res.yres;
	while (--j >= 0)
	{
		i = -1;
		while (++i < scene->res.xres)
		{
			ray = camera_get_ray(&scene->camera, (double)i
					/ scene->res.xres, (double)j / scene->res.yres);
			color = calc_color(&ray, objects);
			put_pixel(data, i, j, create_trgb_vec(&color));
		}
	}
}
