/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2023/01/07 19:33:53 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "structs.h"
# include "libft.h"
# include "styling.h"

typedef int	(*t_create_func)(t_scene *, t_list **, char **);

void		render_gradient(t_data *data);
void		render_image(t_data *data, t_object *objects);
char		**parse_conf_file(char *filename);
void		populate_scene(char **conf, t_scene *scene, t_list **objects);

t_vec		convrt_to_vec(const char *conf);
int			is_vec_format(const char *conf);
int			create_cam(t_scene *scene, t_list **objects, char **conf);
int			create_ambient(t_scene *scene, t_list **objects, char **conf);

int			create_trgb(int t, int r, int g, int b);
int			create_trgb_vec(t_vec *color);
void		put_pixel(t_data *data, int x, int y, int color);
int			handle_key_release(int keycode, t_data *vars);
char		*get_next_line(int fd);

double		get(t_vec *vec, enum e_vec_type c);
void		set(t_vec *vec, enum e_vec_type c, double value);
t_vec		new_vect(double e1, double e2, double e3);

t_vec		v_multi(t_vec vec1, t_vec vec2);
t_vec		v_div(t_vec vec1, t_vec vec2);
t_vec		v_sum(t_vec vec1, t_vec vec2);
t_vec		v_subtr(t_vec vec1, t_vec vec2);
t_vec		v_multi_d(t_vec vec1, double d);
t_vec		v_div_d(t_vec vec1, double d);

double		length(t_vec vec);
t_vec		unit_vec(t_vec vec);
double		dot(t_vec v1, t_vec v2);

double		hit_sphere(t_vec center, double rad, t_ray r);

t_vec		point_at_parameter(t_ray ray, double t);

#endif
