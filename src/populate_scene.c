/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:43:26 by jatan             #+#    #+#             */
/*   Updated: 2023/01/16 13:37:15 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// #include "libft.h"
#include <stdio.h>

t_scene	init_scene(void)
{
	t_scene	ret;

	// ret->light = 0;
	// (void)ret.light;
	ret.camera.init = 0;
	ret.ambient.init = 0;
	// ret.light->init = 0;
	return (ret);
}

/**
 * @brief run this when populate_scene has error to free previous objects
 * in linked list
 *
 * @param objects linked list to free
 */
void	populate_error(t_list **objects, t_list **lights)
{
	ft_putstr_fd(RED"Error: Unabale to populate scene\n"RESET, 2);
	ft_lstclear(objects, free);
	ft_lstclear(lights, free);
}

/**
 * a function to create different object and add to linked list, if got error,
 * need to free the objects created
 * Errors:
 * - invalid identifier, not enough information, wrong information format
*/
int	identify(char *line)
{
	int		i;
	char	**identifier;

	identifier = ft_split(CONFIG_ID, ',');
	i = -1;
	while (identifier[++i])
	{
		if (ft_strncmp(identifier[i], line, ft_strlen(line)) == 0)
		{
			ft_free_array(identifier);
			free(identifier);
			return (i);
		}
	}
	ft_free_array(identifier);
	free(identifier);
	return (-1);
}


void	show_objects(void *content)
{
	t_object	*obj;

	obj = (t_object *)content;
	printf("id: %c\t", (obj->id + 48));
	show_vec(obj->obj.sp.center);
}

/**
 * for each line in conf, split with space, identify identifier, keep track
 * of A, C, L(only can have one of these), run different create for each
*/
void	populate_scene(char **conf, t_scene *scene, t_list **objects)
{
	char		**line;
	int			id;
	t_crt_func	*create_funcs;

	create_funcs = set_crt_funcs();
	*scene = init_scene();
	while (*conf)
	{
		line = ft_split(*conf, ' ');
		id = identify(line[0]);
		if (id == -1)
			break ;
		if (create_funcs[id](scene, objects, line) == -1)
		{
			populate_error(objects, &scene->light);
			ft_free_array(line);
			free(line);
			break ;
		}
		// printf("hmm?\n");
		ft_free_array(line);
		free(line);
		conf++;
	}
	ft_lstiter(*objects, show_objects);
	free(create_funcs);
}
