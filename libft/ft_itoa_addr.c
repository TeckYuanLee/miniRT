/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:19:24 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:19:24 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_addr(size_t n)
{
	char	hex[18];
	char	buffer[14];
	int		i;

	if (n == 0)
		return (ft_strdup("(nil)"));
	ft_strlcpy(hex, "0123456789abcdef", 17);
	ft_strlcpy(buffer, "0x", 3);
	i = 2;
	while (n >= 16)
	{
		buffer[i++] = hex[(n % 16)];
		n /= 16;
	}
	buffer[i++] = hex[(n % 16)];
	buffer[i] = '\0';
	ft_reverse(buffer, 2, i - 1);
	return (ft_strdup(buffer));
}
