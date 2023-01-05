/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conf_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:01:22 by jatan             #+#    #+#             */
/*   Updated: 2023/01/05 10:44:22 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

char	**get_lines_array(int fd)
{
	char	*tmp;
	char	*line;
	char	*prevline;

	line = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		prevline = line;
		line = ft_strjoin(line, tmp);
		free(prevline);
	}
	if (ft_strlen(line) < 1)
		return (NULL);
	return (ft_split(line, '\n'));
}

void	create_world(char **line_array)
{
	while (*line_array)
	{
		ft_putstr_fd(*line_array, 1);
		ft_putchar_fd('\n', 1);
		line_array++;
	}
}

t_object	*parse_conf_file(char *filename)
{
	int		fd;
	char	**line_array;

	if (ft_strnstr(filename, ".rt", ft_strlen(filename)) == NULL)
	{
		ft_putstr_fd
			("Error: argument input file should have \".rt\" extension.\n", 2);
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error at opening config file: ");
		return (NULL);
	}
	line_array = get_lines_array(fd);
	create_world(line_array);
	return (NULL);
}

// todo - error handling, check file, read line, split line, check line, make object

