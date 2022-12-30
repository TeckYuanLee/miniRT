/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2022/12/28 16:42:11 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

typedef struct s_vector
{
    double x;
    double y;
    double z;
    double w;//what's this again? and is this necessary?
} t_vector;

typedef struct s_color
{
    char r;
    char g;
    char b;
} t_color;

typedef struct  s_ray
{
    t_vector    origin;
    t_vector    direction;
}               t_ray;


union  u_objects
{
  t_square    sq;
  t_plane     pl;
  t_sphere    sp;
  t_cylinder  cy;
  t_triangle  tr;
};

typedef struct s_plane
{
    t_vector coor;
    t_vector orientation; // -1, 1
    t_color color;
} t_plane;

typedef struct s_triangle
{
    t_vector pt_one;
    t_vector pt_two;
    t_vector pt_three;
    t_color color;
} t_triangle;

typedef struct  s_sphere
{
    t_vector    center;
    double      radius;
    t_color     color;
}               t_sphere;

typedef struct  s_cylinder
{
    t_vector    center;
    double      radius;
    double      height;
    t_color     color;
}              t_cylinder;

typedef struct  s_square
{
    t_vector    center;
    double      radius;
    t_color     color;
}               t_square;

typedef struct  s_cube
{
    union u_objects sq;
    t_vector        center;
    t_color         color;
}               t_cube;

typedef struct s_object
{
    union u_objects obj;
    t_color         color;//what if we put color here rather than repeating in all the obj structs?
    struct s_object *next;//linked list of objects
} t_object;

typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

typedef struct  s_camera
{
    int         init;
    t_vector    origin;
    t_vector    nv;//normalized vector
    int         fov;
}               t_camera;

typedef struct  s_res
{
  int   res_init;
  int   xres;
  int   yres;
}               t_res;

void put_pixel(t_data *data, int x, int y, int color);
int handle_key_release(int keycode, t_data *vars);

#endif
