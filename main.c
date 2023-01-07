/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:30:39 by jatan             #+#    #+#             */
/*   Updated: 2023/01/07 17:56:33 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "minirt.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	// t_data		data;
	char		**configs;
	t_scene		scene;
	t_list		*objects;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid arguments.\n", 2);
		return (-1);
	}
	objects = NULL;
	configs = parse_conf_file(argv[1]);
	populate_scene(configs, &scene, &objects);
	ft_free_array(configs);
	free(configs);
	// data.mlx = mlx_init();
	// data.w = 600;
	// data.h = 300;
	// data.win = mlx_new_window(data.mlx, data.w, data.h, "miniRT");
	// data.img = mlx_new_image(data.mlx, data.w, data.h);
	// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
	// 		&data.line_length, &data.endian);
	// render_image(&data, NULL);
	// mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	// mlx_hook(data.win, 3, 1L << 1, handle_key_release, &data);
	// mlx_loop(data.mlx);
}
