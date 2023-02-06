/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:08:27 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 17:09:29 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int	create_res(t_scene *scene, t_list **objects, char **conf)
{
	t_res	*res;

	(void) objects;
	res = &(scene->res);
	if (!conf[2] || conf[3])
		return (error("Resolution config invalid", -1));
	res->xres = ft_atoi(conf[1]);
	res->yres = ft_atoi(conf[2]);
	return (0);
}
