/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:00:54 by jatan             #+#    #+#             */
/*   Updated: 2023/01/16 17:29:58 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "create.h"

// * identifier: pl
// * x,y,z coordinates: 0.0,0.0,-10.0
// * 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
// 0.0,0.0,1.0
// * R,G,B colors in range [0-255]: 0, 0, 255

int	create_pl(t_scene *scene, t_list **objects, char **conf)
{
	t_object	*obj;

	(void)scene;
	obj = malloc(sizeof(t_object));
	if (obj == NULL)
	{
		perror(RED"Error: create cy: "RESET);
		return (-1);
	}
	obj->id = pl;
	if (is_vec_format(conf[1]) && is_vec_format(conf[2])
		&& is_vec_format(conf[3]))
		return (error("Plane vector in wrong format", -1));
	obj->obj.pl.coor = convrt_to_vec(conf[1]);
	obj->normal = convrt_to_vec(conf[2]);
	// if (check_nv(obj->obj.pl.nv))
	// 	return (error("Plane normalized orientation vector invalid", -1));
	obj->color = convrt_to_int(conf[3]);
	ft_lstadd_front(objects, ft_lstnew(obj));
	return (0);
}
