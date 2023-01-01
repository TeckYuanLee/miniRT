/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:36 by jatan             #+#    #+#             */
/*   Updated: 2022/12/30 22:48:44 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_trgb_vec(t_vector *color)
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

void	render_gradient(t_data *data)
{
	int			x;
	int			y;
	t_vector	color;

	y = HEIGHT;
	while (--y >= 0)
	{
		x = -1;
		while (++x < WIDTH)
		{
			set(&color, r, (double)x / WIDTH);
			set(&color, g, (double)y / HEIGHT);
			set(&color, b, 0.2);

			put_pixel(data, x, y, create_trgb_vec(&color));
		}
	}
}
