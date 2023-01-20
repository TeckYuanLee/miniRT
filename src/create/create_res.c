/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:08:27 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 10:14:16 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int	create_res(t_scene *scene, t_list **objects, char **conf)
{
	t_res	*res;

	(void) objects;
	res = &(scene->res);
	res->xres = ft_atoi(conf [1]);
	res->yres = ft_atoi(conf[2]);
	return (0);
}
