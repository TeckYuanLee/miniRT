/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:19:51 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:19:52 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pt1;
	char	*pt2;

	if (!dest && !src)
		return (NULL);
	pt1 = (char *)dest;
	pt2 = (char *)src;
	while (n--)
	{
		*pt1++ = *pt2++;
	}
	return (dest);
}
