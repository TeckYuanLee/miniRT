/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:36 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 10:22:11 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>


void	render_gradient(t_data *data)
{
	int			x;
	int			y;
	t_vec	color;

	y = data->h;
	while (--y >= 0)
	{
		x = -1;
		while (++x < data->w)
		{
			set(&color, r, (double)x / data->w);
			set(&color, g, (double)y / data->h);
			set(&color, b, 0.2);

			put_pixel(data, x, y, create_trgb_vec(&color));
		}
	}
}
