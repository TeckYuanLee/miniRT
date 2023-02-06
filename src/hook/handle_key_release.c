/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_release.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:52:19 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 18:12:16 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

int	handle_key_release(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		free(data->mlx);
		ft_lstclear(&data->objects, free);
		system("leaks miniRT");
		exit(0);
	}
	return (0);
}
