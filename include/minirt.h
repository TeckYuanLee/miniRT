/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2022/12/30 15:22:32 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vector;

// typedef struct s_color
// {
// 	char r;
// 	char g;
// 	char b;
// } t_color;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;


union u_objects
{
	t_square	sq;
	t_plane		pl;
	t_sphere	sp;
	t_cylinder	cy;
	t_triangle	tr;
};

typedef struct s_plane
{
	t_vector	coor;
	t_vector	orientation;
}				t_plane;

typedef struct s_triangle
{
	t_vector	pt_one;
	t_vector	pt_two;
	t_vector	pt_three;
}				t_triangle;

typedef struct s_sphere
{
	t_vector	center;
	double		radius;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector	center;
	double		radius;
	double		height;
}				t_cylinder;

typedef struct s_square
{
	t_vector	center;
	double		radius;
}				t_square;

typedef struct s_cube
{
	union u_objects	sq;
	t_vector		center;
}	t_cube;

//what if we put color here rather than repeating in all the obj structs?
//linked list of objects
typedef struct s_object
{
	char			flag;
	union u_objects	obj;
	t_vector		color;
	struct s_object	*next;
}				t_object;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// nv = normalized vector
typedef struct s_camera
{
	int			init;
	t_vector	origin;
	t_vector	nv;
	int			fov;
}				t_camera;

typedef struct s_res
{
	int	res_init;
	int	xres;
	int	yres;
}				t_res;

void	put_pixel(t_data *data, int x, int y, int color);
int		handle_key_release(int keycode, t_data *vars);

#endif
