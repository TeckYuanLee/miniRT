/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:22 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:20:23 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[h] && h < len)
	{
		n = 0;
		while (big[h + n] == little[n] && big[h + n] && (h + n) < len)
		{
			if (little[n + 1] == '\0')
				return ((char *)(big + h));
			n++;
		}
		h++;
	}
	return (NULL);
}
