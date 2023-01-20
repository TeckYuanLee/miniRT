/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:30:39 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 10:59:21 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "minirt.h"
// #include "libft.h"
#include <stdio.h>

void	init_data(t_data *data)
{
	int	xres;
	int	yres;

	data->mlx = mlx_init();
	xres = data->scene.res.xres;
	yres = data->scene.res.yres;
	data->win = mlx_new_window(data->mlx, xres, yres, "miniRT");
	data->img.mlx_img = mlx_new_image(data->mlx, xres, yres);
	data->img.addr = (int *)mlx_get_data_addr(data->img.mlx_img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
}


/**
 * @brief a function to call the ray tracing function and put image on window
 * Can just change the `render_image` function to your own ray trace function
 *
 * @param data
 * @return int
 */
int	render(t_data data)
{
	if (data.win == NULL)
		return (1);
	// render_image(data, &data->scene, data.objects);
	render_scene(data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 0, 0);
	ft_putstr_fd("Rendered image and putted image to window...\n", 1);
	return (0);
}


// Have to initialize objects and ligths pointer to NULL, else there will be
// garbage value in it and caused the linked list to fail (line 66, 67)
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
	data.scene.lights = NULL;
	configs = parse_conf_file(argv[1]);
	populate_scene(configs, &data.scene, &data.objects);
	ft_free_array(configs);
	free(configs);
	init_data(&data);
	render(data);
	mlx_hook(data.win, 3, 1L << 1, handle_key_release, &data);

	mlx_loop(data.mlx);

	mlx_destroy_image(data.mlx, data.img.mlx_img);
	free(data.mlx);
	ft_lstclear(&data.objects, free);
	return (0);
}
