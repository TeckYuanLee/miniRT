/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:32:10 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 16:13:59 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "structs.h"
# include "libft.h"
# include "styling.h"
# include <math.h>
# include <stdio.h>

typedef int			(*t_crt_func)(t_scene *, t_list **, char **);

char		**parse_conf_file(char *filename);
void		populate_scene(char **conf, t_scene *scene, t_list **objects);
char		*get_next_line(int fd);

t_vec		convrt_to_vec(const char *conf);
int			convrt_to_int(const char *conf);
int			is_vec_format(const char *conf);
t_crt_func	*set_crt_funcs(void);


int			handle_key_release(int keycode, t_data *vars);
int	        exit_win(t_data *data);

int			error(char *message, int err_code);

// ----- VECTOR UTILS AND MATHS -----

double		get(t_vec *vec, enum e_vec_type c);
void		show_vec(t_vec vec);

t_vec		v_multi_d(t_vec vec1, double d);
t_vec		v_div_d(t_vec vec1, double d);

t_vec		v_multi(t_vec vec1, t_vec vec2);
t_vec		v_div(t_vec vec1, t_vec vec2);
t_vec		v_sum(t_vec vec1, t_vec vec2);
t_vec		v_subtr(t_vec vec1, t_vec vec2);
double		v_cos(t_vec a, t_vec b);

double		length(t_vec vec);
double		dot(t_vec v1, t_vec v2);
t_vec		cross(t_vec v1, t_vec v2);
t_vec		normalize(t_vec p);
double		distance(t_vec p1, t_vec p2);

// ------ rendering functions -----

void		render_scene(t_data *data);
int			trace_ray(t_ray *ray, t_data *data);
int			light_itsxn(t_vec o, t_vec d, t_list *lst);
void		calc_light(t_itsxn *itsxn, t_list *lights, t_ambient ambient, t_list *lst);
double      solve_pl(t_vec o, t_vec d, t_vec c, t_vec nv);
double		solve_sp(t_vec o, t_vec d, t_object *lst);
void		ray_itsxn(t_ray *ray, t_list *objects, t_object *closest_obj, double *closest_itsxn);

double      solve_cy(t_vec o, t_vec d, t_object *lst);

#endif
