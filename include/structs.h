/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:30:30 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 10:20:31 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum e_vec_type {x=0, y=1, z=2, r=0, g=1, b=2};
typedef struct s_vector
{
	double	e1;
	double	e2;
	double	e3;
	double	e4;
}				t_vec;

typedef struct s_plane
{
	t_vec	coor;
	t_vec	orientation;
}				t_plane;

typedef struct s_triangle
{
	t_vec	pt_one;
	t_vec	pt_two;
	t_vec	pt_three;
}				t_triangle;

typedef struct s_sphere
{
	t_vec	center;
	double		radius;
}				t_sphere;

typedef struct s_cylinder
{
	t_vec	center;
	double		radius;
	double		height;
}				t_cylinder;

typedef struct s_square
{
	t_vec	center;
	double		radius;
}				t_square;

// typedef struct s_cube
// {
// 	union u_objects	sq;
// 	t_vec		center;
// }	t_cube;


union u_objects
{
	t_square	sq;
	t_plane		pl;
	t_sphere	sp;
	t_cylinder	cy;
	t_triangle	tr;
};

//what if we put color here rather than repeating in all the obj structs?
//linked list of objects
typedef struct s_object
{
	char			flag;
	union u_objects	obj;
	t_vec		color;
	struct s_object	*next;
}				t_object;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}				t_ray;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_data;

// nv = normalized vector
typedef struct s_camera
{
	int		init;
	t_vec	origin;
	t_vec	nv;
	int		fov;
}				t_camera;

typedef struct s_res
{
	int	res_init;
	int	xres;
	int	yres;
}				t_res;

#endif
