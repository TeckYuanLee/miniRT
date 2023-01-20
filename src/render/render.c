/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:44:44 by telee             #+#    #+#             */
/*   Updated: 2023/01/20 12:08:24 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


//rotate the vector 'd' in such a way that it points towards
//the camera's normal vector 'cam_nv'
static t_vec	cam_direction(t_vec d, t_vec cam_nv)
{
	t_vec	x_axis;
	t_vec	y_axis;
	t_vec	z_axis;
	t_vec	rotated;

	y_axis = new_vect(0, 1, 0);
	z_axis = cam_nv;
	if (cam_nv.e2 == 1)
		x_axis = new_vect(1, 0, 0);
	else if (cam_nv.e2 == -1)
		x_axis = new_vect(-1, 0, 0);
	else
		x_axis = cross(y_axis, z_axis);
	y_axis = cross(z_axis, x_axis);
	rotated.e1 = d.e1 * x_axis.e1 + d.e2 * y_axis.e1 + d.e3 * z_axis.e1;
	rotated.e2 = d.e1 * x_axis.e2 + d.e2 * y_axis.e2 + d.e3 * z_axis.e2;
	rotated.e3 = d.e1 * x_axis.e3 + d.e2 * y_axis.e3 + d.e3 * z_axis.e3;
	return (rotated);
}

//determine position of a point in 3D space (map 2d pixel to 3d scene)
static t_vec	cam_position(int w, int h, t_scene *scene)
{
	double		asp_ratio;
	double		adj_fov;
	double		e1;
	double		e2;
	t_vec		point;

	e1 = (double)w / scene->res.xres;
	e2 = (double)h / scene->res.yres;
	asp_ratio = (double)(scene->res.xres) / (double)(scene->res.yres);
	adj_fov = tan((scene->camera.fov * M_PI / 180) / 2);
	point.e1 = (((2 * e1) - 1) * asp_ratio * adj_fov) * -1;
	point.e2 = (1 - (2 * e2)) * adj_fov;
	point.e3 = 1;
	return (point);
}

/**
 * ----- render_scene_v1, for reference -----
 *
 * 	rt.data.bgr = 0x202020;
 *	rt.j = 0;
 *	while (rt.j < rt.data.yres)
 *	{
 *		rt.i = 0;
 *		while (rt.i < rt.data.xres)
 *		{
 *			color = calc_ray(rt);
 *			rt.mlx.addr[rt.j * rt.data.xres + rt.i] = color;
 *			rt.i++;
 *		}
 *		printf("\rRendering scene... [%.2f%%]",
 *			(double)100 * rt.j / rt.data.yres);
 *		rt.j++;
 *	}
 *	printf("\rRendering scene... [100%%]\n");s
 */


void	render_scene(t_data data, t_scene *scene, t_list *objects)
{
	int		color;
	int		h;
	int		w;
	t_vec	ray;

	scene->background = 0x202020;
	h = 0;
	while (h < scene->res.yres)
	{
		w = 0;
		while (w < scene->res.xres)
		{
			ray = cam_position(w, h, scene);
			ray = cam_direction(ray, scene->camera.nv);
			color = trace_ray(ray, data);
			data.img.addr[h * scene->res.xres + w] = color;
			w++;
		}
		printf("\rRendering scene... [%.2f%%]",
			(double)100 * h / data.scene.res.yres);
		h++;
	}
	printf("\rRendering scene... [100%%]\n");
}
