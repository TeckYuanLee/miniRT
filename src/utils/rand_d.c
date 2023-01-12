/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:14:49 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 14:30:54 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// x0=seed; a=multiplier; b=increment; m=modulus;
double	rand_d(int seed, double min, double max)
{
	static int	prev_seed;
	int			mod;
	double		scaled_random;

	prev_seed += seed;
	mod = seed + 42;
	prev_seed = (42 * prev_seed + 42) % mod;
	scaled_random = min + ((double)prev_seed / mod) * (max - min);
	return (scaled_random);
}

