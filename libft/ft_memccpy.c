/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:19:47 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:19:48 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  memccpy()  function copies no more than n bytes from memory area src
       to memory area dest, stopping when the character c is found.

       If the memory areas overlap, the results are undefined. */

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;

	pt1 = (unsigned char *)dest;
	pt2 = (unsigned char *)src;
	while (n--)
	{
		if (*pt2 == (unsigned char)c)
		{
			*pt1 = *pt2;
			return ((void *)++pt1);
		}
		*pt1++ = *pt2++;
	}
	return (NULL);
}
