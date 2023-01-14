/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:10:07 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 18:31:12 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	create_cam(t_scene *scene, t_list **objects, char **conf)
{
	t_camera	*cam;
	int			fov;

	(void) objects;
	cam = &(scene->camera);
	// if (cam->init != 0)
	// {
	// 	ft_putstr_fd(RED"Error: Have multiple camera config\n"RESET, 2);
	// 	return (-1);
	// }
	if (is_vec_format(conf[1]) && is_vec_format(conf[2]))
	{
		ft_putstr_fd(RED"Error: Camera vectors in wrong format\n"RESET, 2);
		return (-1);
	}
	cam->origin = convrt_to_vec(conf[1]);
	cam->nv = convrt_to_vec(conf[2]);
	fov = ft_atoi(conf[3]);
	if (fov < 0 || fov > 180)
	{
		ft_putstr_fd(RED"Error: Camera fov not in range [0, 180]\n"RESET, 2);
		return (-1);
	}
	cam->fov = fov;
	cam->init = 1;
	return (0);
}
