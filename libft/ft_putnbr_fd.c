/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:00 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:20:02 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
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
	write(fd, buffer, ft_strlen(buffer));
}

void	ft_reverse(char *buffer, int i, int j)
{
	char	tmp;

	while (i < j)
	{
		tmp = buffer[i];
		buffer[i++] = buffer[j];
		buffer[j--] = tmp;
	}
}
