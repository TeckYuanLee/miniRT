/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:06 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:20:07 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*add_word(const char *s, int *i, char c);
int		find_word(char *s, int *num, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = find_word((char *)s, &i, c);
	array = (char **)malloc (sizeof(*array) * (count + 1));
	if (array == NULL)
		return (NULL);
	i--;
	array[count] = NULL;
	while (count--)
		array[count] = add_word(s, &i, c);
	return (array);
}

int	find_word(char *s, int *num, char c)
{
	int	count;
	int	i;

	i = *num;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	*num = i;
	return (count);
}

char	*add_word(const char *s, int *i, char c)
{
	int		idx1;
	int		idx2;

	while (*i >= 0 && s[*i] == c)
		(*i)--;
	idx2 = *i + 1;
	while (*i >= 0 && s[*i] != c)
		(*i)--;
	idx1 = *i + 1;
	return (ft_substr(s, idx1, idx2 - idx1));
}

// static int	wordcount(const char *s, char c)
// {
// 	int	i;
// 	int	count;
// 	int	isword;

// 	i = 0;
// 	count = 0;
// 	isword = 0;
// 	while (s[i])
// 	{
// 		if (isword == 0 && s[i] != c)
// 		{
// 			count++;
// 			isword = 1;
// 		}
// 		else if (s[i] == c)
// 			isword = 0;
// 		i++;
// 	}
// 	return (count);
// }

// char	**ft_split(const char *s, char c)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**ptr;

// 	i = 0;
// 	k = 0;
// 	if (!s)
// 		return (0);
// 	ptr = ft_calloc((wordcount(s, c) + 1), 8);
// 	if (!ptr)
// 		return (0);
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			j = 0;
// 			while (s[i + j + 1] != c && s[i + j + 1])
// 				j++;
// 			i += j;
// 			ptr[k] = malloc(j);
// 			ft_strlcpy(ptr[k++], (char *)&(s[i - j]), j + 2);
// 		}
// 		i++;
// 	}
// 	return (ptr);
// }
