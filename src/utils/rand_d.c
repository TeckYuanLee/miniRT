/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:14:49 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 12:03:15 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

// x0=seed; a=multiplier; b=increment; m=modulus;
double	rand_d(int pseed)
{
	static long	seed;

	if (pseed != 0)
		seed = pseed;
	if (seed == 0)
		seed = 1;
	seed = (0x5deece66dLL * seed + 0xb) & ((1LL << 48) - 1);
	return ((double)seed / (double)((1LL << 48) - 1));
}
