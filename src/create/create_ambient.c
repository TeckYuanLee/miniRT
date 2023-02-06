/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:10:07 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 17:08:41 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <stdio.h>

int	create_ambient(t_scene *scene, t_list **objects, char **conf)
{
	t_ambient	*ambient;

	(void) objects;
	ambient = &(scene->ambient);
	if (ambient->init != 0)
		return (error("Have multiple ambient config", -1));
	if (!conf[2] || conf[3])
		return (error("Ambient config invalid", -1));
	ambient->ratio = ft_atod(conf[1]);
	if (ambient->ratio < 0.0 || ambient->ratio > 1.0)
		return (error("Ambient ratio not in range [0.0, 1.0]", -1));
	if (is_vec_format(conf[2]))
		return (error("Ambient vector in wrong format", -1));
	ambient->color = convrt_to_int(conf[2]);
	ambient->init = 1;
	return (0);
}
