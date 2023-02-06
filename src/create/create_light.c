/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:10:07 by jatan             #+#    #+#             */
/*   Updated: 2023/01/16 14:55:40 by jatan            ###   ########.fr       */
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
	if (is_vec_format(conf[1]) && is_vec_format(conf[2]))
		return (error("Light vector in wrong format", -1));
	light->coor = convrt_to_vec(conf[1]);
	light->ratio = ft_atod(conf[2]);
	if (light->ratio < 0.0 || light->ratio > 1.0)
		return (error("Light ratio not in range [0.0, 1.0]", -1));
	light->color = convrt_to_int(conf[3]);
	ft_lstadd_front(&scene->lights, ft_lstnew(light));
	return (0);
}
