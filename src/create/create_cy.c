/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:00:54 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 17:09:05 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "create.h"

// * 0 -> identifier: cy
// * 1 -> x,y,z coordinates: 50.0,0.0,20.6
// * 2 -> 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
// * (0.0,0.0,1.0)
// * 3 -> the cylinder diameter: 14.2
// * 4 -> the cylinder height: 21.42
// * 5 -> R,G,B colors in range [0,255]: 10,0,255

int	create_cy(t_scene *scene, t_list **objects, char **conf)
{
	t_object	*obj;

	(void)scene;
	if (!conf[5] || conf[6])
		return (error("Cylinder config invalid", -1));
	obj = malloc(sizeof(t_object));
	if (obj == NULL)
	{
		perror(RED"Error: create cy: "RESET);
		return (-1);
	}
	obj->id = cy;
	if (is_vec_format(conf[1]) || is_vec_format(conf[2])
		|| is_vec_format(conf[5]))
		return (error("Cylinder vector in wrong format", -1));
	obj->obj.cy.center = convrt_to_vec(conf[1]);
	obj->obj.cy.nv = convrt_to_vec(conf[2]);
	if (check_nv(obj->obj.cy.nv))
		return (error("Cylinder orientation normalized vector invalid", -1));
	obj->obj.cy.radius = ft_atod(conf[3]) / 2;
	obj->obj.cy.height = ft_atod(conf[4]);
	obj->color = convrt_to_int(conf[5]);
	ft_lstadd_front(objects, ft_lstnew(obj));
	return (0);
}
