/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:55:56 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 15:41:15 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_H
# define CREATE_H

# include "minirt.h"

typedef int	(*t_crt_func)(t_scene *, t_list **, char **);

int			create_cam(t_scene *scene, t_list **objects, char **conf);
int			create_res(t_scene *scene, t_list **objects, char **conf);
int			create_ambient(t_scene *scene, t_list **objects, char **conf);
int			create_light(t_scene *scene, t_list **objects, char **conf);
int			create_sp(t_scene *scene, t_list **objects, char **conf);
int			create_cy(t_scene *scene, t_list **objects, char **conf);
int			create_pl(t_scene *scene, t_list **objects, char **conf);

t_vec		convrt_to_vec(const char *conf);
int			convrt_to_int(const char *conf);
int			is_vec_format(const char *conf);
int			check_nv(t_vec vec);

#endif
