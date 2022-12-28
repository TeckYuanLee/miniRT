/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2022/12/28 19:14:55 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1000
# define HEIGHT 800


typedef struct s_vector
{
	double	e1;
	double	e2;
	double	e3;
	double	e4;
}				t_vector;

typedef struct s_color
{
	char	r;
	char	g;
	char	b;
}				t_color;

typedef struct s_plane
{
	t_vector	coor;
	t_vector	orientation;
	t_color		color;
}				t_plane;

typedef struct s_triangle
{
	t_vector	pt_one;
	t_vector	pt_two;
	t_vector	pt_three;
	t_color	olor;
}				t_triangle;

// to-do cube

typedef struct s_object
{

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

void	put_pixel(t_data *data, int x, int y, int color);
int		handle_key_release(int keycode, t_data *vars);

void	render_gradient(t_data *data);


#endif
