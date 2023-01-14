/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:10:07 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 18:36:46 by jatan            ###   ########.fr       */
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
	// if (ambient->init != 0)
	// 	return (error("Have multiple ambient config", -1));
	ambient->ratio = ft_atod(conf[1]);
	if (ambient->ratio < 0.0 || ambient->ratio > 1.0)
		return (error("Ambient ratio not in range [0.0, 1.0]", -1));
	if (is_vec_format(conf[2]))
		return (error("Ambient vector in wrong format", -1));
	// ambient->color = v_div_d(convrt_to_vec(conf[2]), 255);
	ambient->color = convrt_to_int(conf[2]);
	ambient->init = 1;
	return (0);
}
