/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:03:24 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 09:35:29 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_trgb_vec(t_vec *color)
{
	int	t;
	int	r_val;
	int	g_val;
	int	b_val;

	t = 0;
	r_val = get(color, r) * 255;
	g_val = get(color, g) * 255;
	b_val = get(color, b) * 255;
	return (t << 24 | r_val << 16 | g_val << 8 | b_val);
}
