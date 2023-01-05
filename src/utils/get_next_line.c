/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:22 by jatan             #+#    #+#             */
/*   Updated: 2023/01/05 10:39:08 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include <unistd.h>

void	join_line(char **line, char *string, int *r);

/*
Malloc buffer and intialized line to NULL for new line.
Only read line when fd is valid and buffer is available.
If line is not NULL but empty, set line to NULL.
Return line.
*/
char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		r;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	r = read(fd, buffer, 0);
	if (r >= 0 && buffer)
	{
		r = 1;
		while (r > 0)
		{
			r = read(fd, buffer, BUFFER_SIZE);
			buffer[r] = 0;
			join_line(&line, buffer, &r);
		}
	}
	if (line && !*line)
	{
		free(line);
		line = NULL;
	}
	free(buffer);
	return (line);
}

/*
1. If store is not NULL, else if line is NULL(when first initialized)
2. If buffer has char and r(read's return) is larger than 0
3. Look for '\n' in line, store address in tmp, if tmp is not NULL
*/
void	join_line(char **line, char *buffer, int *r)
{
	static char	*store;
	char		*tmp;

	if (store)
	{
		*line = ft_strdup(store);
		free(store);
		store = NULL;
	}
	else if (!*line)
		*line = ft_strdup("");
	if (*buffer && *r > 0)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	tmp = ft_strchr(*line, '\n');
	if (tmp)
	{
		store = ft_strdup(tmp + 1);
		*(++tmp) = '\0';
		*r = 0;
	}
}
