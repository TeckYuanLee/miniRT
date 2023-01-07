/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:43:26 by jatan             #+#    #+#             */
/*   Updated: 2023/01/07 18:08:24 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

t_scene	init_scene(void)
{
	t_scene ret;

	ret.camera.init = 0;
	ret.ambient.init = 0;
	ret.light.init = 0;
	return (ret);
}

/**
 * @brief run this when populate_scene has error to free previous objects
 * in linked list
 *
 * @param objects linked list to free
 */
void	populate_error(t_list **objects)
{
	ft_putstr_fd(RED"Error: Unabale to populate scene\n"RESET, 2);
	ft_lstclear(objects, free);
}

/**
 * a function to create different object and add to linked list, if got error,
 * need to free the objects created
 * Errors:
 * - invalid identifier, not enough information, wrong information format
*/
int	identify(char **identifier, char *line)
{
	int			i;

	i = -1;
	while (identifier[++i])
	{
		if (ft_strncmp(identifier[i], line, ft_strlen(line)) == 0)
			return (i);
	}
	return (-1);
}

t_create_func	*set_create_funcs(void)
{
	t_create_func	*funcs;

	funcs = (t_create_func *)malloc(sizeof(t_create_func) * L + 1);

	funcs[sp] = NULL;
	funcs[pl] = NULL;
	funcs[cy] = NULL;
	funcs[A] = NULL;
	funcs[C] = create_cam;
	funcs[L] = NULL;

	return (funcs);
}

/**
 * for each line in conf, split with space, identify identifier, keep track
 * of A, C, L(only can have one of these), run different create for each
*/
void	populate_scene(char **conf, t_scene *scene, t_list **objects)
{
	char			**line;
	char			**identifier;
	int				id;
	t_create_func	*create_funcs;

	identifier = ft_split(CONFIG_ID, ',');
	create_funcs = set_create_funcs();
	*scene = init_scene();
	while (*conf)
	{
		line = ft_split(*conf, ' ');
		id = identify(identifier, line[0]);
		if (id == -1)
			break ;
		if (id == C && create_funcs[id](scene, objects, line) == -1)
			populate_error(objects);
		ft_free_array(line);
		free(line);
		conf++;
	}
	ft_free_array(identifier);
	free(identifier);
}
