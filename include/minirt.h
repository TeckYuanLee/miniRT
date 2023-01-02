/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2023/01/02 13:42:10 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1000
# define HEIGHT 800

# include "structs.h"


void		render_gradient(t_data *data);
void		render_image(t_data *data, t_object *objects);



int			create_trgb(int t, int r, int g, int b);
int			create_trgb_vec(t_vector *color);
void		put_pixel(t_data *data, int x, int y, int color);
int			handle_key_release(int keycode, t_data *vars);

double		get(t_vector *vec, enum e_vec_type c);
void		set(t_vector *vec, enum e_vec_type c, double value);
t_vector	new_vect(double e1, double e2, double e3);

t_vector	v_multi(t_vector vec1, t_vector vec2);
t_vector	v_div(t_vector vec1, t_vector vec2);
t_vector	v_sum(t_vector vec1, t_vector vec2);
t_vector	v_subtr(t_vector vec1, t_vector vec2);
t_vector	v_multi_d(t_vector vec1, double d);
t_vector	v_div_d(t_vector vec1, double d);

double		length(t_vector vec);
t_vector	unit_vector(t_vector vec);



#endif
