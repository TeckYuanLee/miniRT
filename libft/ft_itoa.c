/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:19:27 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:19:27 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			buffer[12];
	unsigned int	unint_n;
	int				i;

	if (n < 0)
		unint_n = (unsigned int)(n * -1);
	else
		unint_n = (unsigned int)(n);
	i = 0;
	while (unint_n >= 10)
	{
		buffer[i++] = (unint_n % 10) + '0';
		unint_n /= 10;
	}
	buffer[i++] = (unint_n % 10) + '0';
	if (n < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
	ft_reverse(buffer, 0, i - 1);
	return (ft_strdup(buffer));
}
