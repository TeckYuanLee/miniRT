/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:14:49 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 17:45:06 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

// x0=seed; a=multiplier; b=increment; m=modulus;
double	rand_d(int pseed, double min, double max)
{
	static int	seed;
	// int			mod;
	// double		scaled_random;

	(void)pseed;
	(void)min;
	(void)max;
	// if (seed < 0)
	// 	prev_seed = seed * -1;
	// else
	// 	prev_seed = seed;
	// mod = prev_seed + 42;
	// prev_seed = (42 * prev_seed + 42) % mod;
	// prev_seed = (0x5DEECE66DL * prev_seed + 0xBL) & ((1L << 48) - 1);
	// scaled_random = min + ((double)prev_seed / mod) * (max - min);
	// printf("%f \n", scaled_random);
	seed = (0x5deece66dLL * seed + 0xb) & ((1LL << 48) - 1);
    return (double)seed / (double)((1LL << 48) - 1);
	// return (scaled_random);
}

