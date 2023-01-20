/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:30:30 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 10:31:02 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

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
	t_vec	nv;
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
	double	radius;
}				t_sphere;

typedef struct s_cylinder
{
	t_vec	center;
	t_vec	nv;
	double	radius;
	double	height;
}				t_cylinder;

typedef struct s_square
{
	t_vec	center;
	double	radius;
}				t_square;

// typedef struct s_cube
// {
// 	union u_objects	sq;
// 	t_vec		center;
// }	t_cube;


# define CONFIG_ID "sp,pl,cy,A,C,R,l"

enum e_id {sp, pl, cy, A, C, R, l};
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
	char			id;
	union u_objects	obj;
	int				color;
	t_vec			normal;
	// struct s_object	*next;
}				t_object;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}				t_ray;

// nv = normalized vector
typedef struct s_camera
{
	char	init;
	t_vec	origin;
	t_vec	nv;
	int		fov;
	t_vec	lower_left_corner;
	t_vec	horizontal;
	t_vec	vertical;
}				t_camera;

typedef struct s_ambient
{
	char	init;
	double	ratio;
	int		color;
}				t_ambient;

typedef struct s_light
{
	// char			init;
	t_vec			coor;
	double			ratio;
	int				color;
	// struct s_light	*next;
}				t_light;

typedef struct s_res
{
	int	xres;
	int	yres;
}				t_res;

typedef struct s_scene
{
	t_res		res;
	t_camera	camera;
	t_ambient	ambient;
	t_list		*lights;
	int			background;
}				t_scene;


typedef struct s_img
{
	void	*mlx_img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	int		xres;
	int		yres;
	void	*mlx;
	void	*win;
	t_img	img;
	int		w;
	int		h;
	t_scene	scene;
	t_list	*objects;
}				t_data;



typedef struct s_itsxn
{
	int		color;
	t_vec	normal;
	t_vec	point;
}				t_itsxn;

typedef struct s_hit_rec {
	t_vec	p;
	t_vec	normal;
	double	t;
	char	hit;
}				t_hit_rec;

#endif
