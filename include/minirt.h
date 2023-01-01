/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2023/01/01 22:04:00 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1000
# define HEIGHT 800

# include "objects.h"


void		render_gradient(t_data *data);
void		render_image(t_data *data);


int			create_trgb(int t, int r, int g, int b);
int			create_trgb_vec(t_vector *color);
void		put_pixel(t_data *data, int x, int y, int color);
int			handle_key_release(int keycode, t_data *vars);

double		get(t_vector *vec, enum e_vec_type c);
void		set(t_vector *vec, enum e_vec_type c, double value);
t_vector	new_vect(double e1, double e2, double e3);


#endif
