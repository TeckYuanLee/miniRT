/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:10:07 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 15:41:01 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int	create_cam(t_scene *scene, t_list **objects, char **conf)
{
	t_camera	*cam;
	int			fov;

	(void) objects;
	cam = &(scene->camera);
	if (is_vec_format(conf[1]) && is_vec_format(conf[2]))
		return (error("Camera vectors in wrong format", -1));
	cam->origin = convrt_to_vec(conf[1]);
	cam->nv = convrt_to_vec(conf[2]);
	fov = ft_atoi(conf[3]);
	if (fov < 0 || fov > 180)
		return (error("Camera fov not in range [0, 180]", -1));
	cam->fov = fov;
	cam->init = 1;
	return (0);
}
