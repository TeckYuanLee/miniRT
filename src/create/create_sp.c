/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:00:54 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 18:12:13 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>
#include <stdio.h>

// * identifier: sp
// * x,y,z coordinates of the sphere center: 0.0,0.0,20.6
// * the sphere diameter: 12.6
// * R,G,B colors in range [0-255]: 10, 0, 255

int	create_sp(t_scene *scene, t_list **objects, char **conf)
{
	t_object	*obj;

	(void)scene;
	obj = malloc(sizeof(t_object));
	if (obj == NULL)
	{
		perror(RED"Error: create sp: "RESET);
		return (-1);
	}
	obj->id = sp;
	if (is_vec_format(conf[1]) && is_vec_format(conf[2]))
		return (error("Sphere vector in wrong format", -1));
	obj->obj.sp.center = convrt_to_vec(conf[1]);
	obj->obj.sp.radius = ft_atod(conf[2]);
	obj->color = v_div_d(convrt_to_vec(conf[3]), 255);
	ft_lstadd_front(objects, ft_lstnew(obj));
	return (0);
}
