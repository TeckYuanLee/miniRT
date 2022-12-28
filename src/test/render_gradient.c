/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:36 by jatan             #+#    #+#             */
/*   Updated: 2022/12/28 19:04:17 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	render_gradient(t_data *data)
{
	int		x;
	int		y;
	double	r;
	double	g;

	y = HEIGHT;
	while (--y >= 0)
	{
		x = -1;
		while (++x < WIDTH)
		{
			r = (double)x / WIDTH;
			g = (double)y / HEIGHT;
			put_pixel(data, x, y,
				create_trgb(0, r * 255, g * 255, 255 * 0.2));
		}
	}
}
