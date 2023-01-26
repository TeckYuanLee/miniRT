/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:00:39 by jatan             #+#    #+#             */
/*   Updated: 2023/01/07 19:20:22 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	apply_exponent(double ret, int e)
{
	while (e > 0)
	{
		ret *= 10.0;
		e--;
	}
	while (e < 0)
	{
		ret *= 0.1;
		e++;
	}
	return (ret);
}

double	calc_exponent(double ret, const char *str, int e)
{
	int	sign;
	int	i;

	if (*str == 'e' || *str == 'E')
	{
		i = 0;
		sign = 1;
		str++;
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		while (*str != '\0' && ft_isdigit(*str))
		{
			i = i * 10 + (*str - '0');
			str++;
		}
		e += i * sign;
	}
	return (apply_exponent(ret, e));
}

int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

// This function stolen from either Rolf Neugebauer or Andrew Tolmach.
// Probably Rolf.
double	ft_atod(const char *str)
{
	double	ret;
	int		e;
	int		sign;

	ret = 0.0;
	e = 0;
	sign = get_sign(&str);
	while (*str != '\0' && ft_isdigit(*str))
	{
		ret = ret * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str != '\0' && ft_isdigit(*str))
		{
			ret = ret * 10.0 + (*str - '0');
			e = e - 1;
			str++;
		}
	}
	ret = calc_exponent(ret, str, e);
	return (ret * sign);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%f\n", ft_atod("-50.3e7"));
// 	printf("%f\n", ft_atod("20.0"));
// 	printf("%f\n", ft_atod("0.0"));

// 	printf("%f\n", -50.3e7);
// 	printf("%f\n", 20.0);
// 	printf("%f\n", 0.0);
// }
