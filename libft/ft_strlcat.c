/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:15 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:20:16 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	d_len;
	size_t	size;

	d = dst;
	s = src;
	size = n;
	while (size-- && *d != 0)
		d++;
	d_len = d - dst;
	size = n - d_len;
	if (size == 0)
		return (d_len + ft_strlen(src));
	while (size-- != 1 && *s)
	{
		*d++ = *s++;
	}
	*d = '\0';
	return (d_len + ft_strlen(src));
}
