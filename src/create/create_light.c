/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:10:07 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 17:13:24 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	create_light(t_scene *scene, t_list **objects, char **conf)
{
	t_light	*light;

	(void) objects;
	if (!conf[3] || conf[4])
		return (error("Light config invalid", -1));
	light = malloc(sizeof(t_light));
	if (light == NULL)
	{
		perror(RED"Error: create light: "RESET);
		return (-1);
	}
	if (is_vec_format(conf[1]) || is_vec_format(conf[3]))
		return (error("Light vector in wrong format", -1));
	light->coor = convrt_to_vec(conf[1]);
	light->ratio = ft_atod(conf[2]);
	if (light->ratio <= 0.0 || light->ratio > 1.0)
		return (error("Light ratio not in range [0.0, 1.0]", -1));
	light->color = convrt_to_int(conf[3]);
	ft_lstadd_front(&scene->lights, ft_lstnew(light));
	return (0);
}
