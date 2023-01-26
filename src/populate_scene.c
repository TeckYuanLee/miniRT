/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:43:26 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 15:36:53 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_scene	init_scene(void)
{
	t_scene	ret;

	ret.camera.init = 0;
	ret.ambient.init = 0;
	ret.lights = NULL;
	return (ret);
}

/**
 * a function to create different object and add to linked list, if got error,
 * need to free the objects created
 * Errors:
 * - invalid identifier, not enough information, wrong information format
*/
int	identify_and_create(
	char **line, t_scene *scene, t_list **objects, t_crt_func *crt_funcs)
{
	int			i;
	static char	**identifier;

	if (identifier == NULL)
		identifier = ft_split(CONFIG_ID, ',');
	i = -1;
	while (identifier[++i])
	{
		if (ft_strncmp(identifier[i], line[0], ft_strlen(line[0])) == 0)
		{
			break ;
		}
	}
	if (i > l)
	{
		ft_putstr_fd(YELLOW"WARNING: Unrecognized characters\n"RESET, 2);
		return (1);
	}
	if (crt_funcs[i](scene, objects, line) == -1)
	{
		return (-1);
	}
	return (1);
}

/**
 * @brief
 *
 * @param content
 */
void	show_objects(void *content)
{
	t_object	*obj;

	obj = (t_object *)content;
	printf("Object:\tid: %c\t", (obj->id + 48));
	show_vec(obj->obj.sp.center);
}

void	show_light(void *light)
{
	printf("Light:\t\t");
	show_vec(((t_light *)light)->coor);
}

/**
 * for each line in conf, split with space, identify identifier, keep track
 * of A, C, L(only can have one of these), run different create for each
*/
void	populate_scene(char **conf, t_scene *scene, t_list **objects)
{
	char		**line;
	int			stat;
	t_crt_func	*create_funcs;

	create_funcs = set_crt_funcs();
	*scene = init_scene();
	while (*conf)
	{
		line = ft_split(*conf, ' ');
		stat = identify_and_create(line, scene, objects, create_funcs);
		if (stat == -1)
		{
			ft_putstr_fd(RED"Error: Unabale to populate scene\n"RESET, 2);
			ft_lstclear(objects, free);
			ft_lstclear(&scene->lights, free);
		}
		ft_free_array(line);
		free(line);
		if (stat == -1)
			break ;
		conf++;
	}
	ft_lstiter(*objects, show_objects);
	ft_lstiter(scene->lights, show_light);
	free(create_funcs);
}
