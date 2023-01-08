/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:30:39 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 18:42:15 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "minirt.h"
#include "libft.h"
#include <stdio.h>

t_data	init_data(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.w = 600;
	data.h = 300;
	data.win = mlx_new_window(data.mlx, data.w, data.h, "miniRT");
	data.img.mlx_img = mlx_new_image(data.mlx, data.w, data.h);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img,
			&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	return (data);
}

int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	render_image(data, NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	char		**configs;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid arguments.\n", 2);
		return (-1);
	}
	data.objects = NULL;
	configs = parse_conf_file(argv[1]);
	populate_scene(configs, &data.scene, &data.objects);
	ft_free_array(configs);
	free(configs);
	data = init_data();

	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, 3, 1L << 1, handle_key_release, &data);

	mlx_loop(data.mlx);

	mlx_destroy_image(data.mlx, data.img.mlx_img);
	free(data.mlx);
	ft_lstclear(&data.objects, free);
	return (0);
}
