/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2022/12/30 22:40:48 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1000
# define HEIGHT 800

# include "objects.h"

void		put_pixel(t_data *data, int x, int y, int color);
int			handle_key_release(int keycode, t_data *vars);

void		render_gradient(t_data *data);

double		get(t_vector *vec, enum e_vec_type c);
void		set(t_vector *vec, enum e_vec_type c, double value);
t_vector	new_vect(double e1, double e2, double e3);


#endif
