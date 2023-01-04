/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:36 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 09:35:29 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>


void	render_gradient(t_data *data)
{
	int			x;
	int			y;
	t_vec	color;

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
