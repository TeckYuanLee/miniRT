/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:55:56 by jatan             #+#    #+#             */
/*   Updated: 2023/01/10 10:55:23 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_H
# define CREATE_H

# include "structs.h"

typedef int	(*t_crt_func)(t_scene *, t_list **, char **);

int			create_cam(t_scene *scene, t_list **objects, char **conf);
int			create_ambient(t_scene *scene, t_list **objects, char **conf);
int			create_light(t_scene *scene, t_list **objects, char **conf);
int			create_sp(t_scene *scene, t_list **objects, char **conf);
int			create_cy(t_scene *scene, t_list **objects, char **conf);
int			create_pl(t_scene *scene, t_list **objects, char **conf);

#endif
