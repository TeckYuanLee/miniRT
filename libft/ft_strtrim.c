/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:24 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:20:25 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_isset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	int	i;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_isset(s1[len - 1], set))
		len--;
	i = 0;
	while (s1[i] && ft_isset(s1[i], set))
	{
		i++;
		len--;
	}
	return (ft_substr(s1, i, len));
}

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i++))
			return (1);
	}
	return (0);
}
