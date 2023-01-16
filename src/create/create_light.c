/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:10:07 by jatan             #+#    #+#             */
/*   Updated: 2023/01/16 13:35:23 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	create_light(t_scene *scene, t_list **objects, char **conf)
{
	t_light	*light;

	(void) objects;
	light = malloc(sizeof(t_light));
	if (light == NULL)
	{
		perror(RED"Error: create light: "RESET);
		return (-1);
	}
	// light = &(*scene->light);
	// if (light->init != 0)
	// 	return (error("Have multiple Light config", -1));
	if (is_vec_format(conf[1]) && is_vec_format(conf[3]))
		return (error("Light vector in wrong format", -1));
	light->coor = convrt_to_vec(conf[1]);
	light->ratio = ft_atod(conf[2]);
	if (light->ratio < 0.0 || light->ratio > 1.0)
		return (error("Light ratio not in range [0.0, 1.0]", -1));
	// light->color = v_div_d(convrt_to_vec(conf[3]), 255);
	light->color = convrt_to_int(conf[3]);
	ft_lstadd_front(&scene->light, ft_lstnew(light));
	// light->init = 1;
	return (0);
}
