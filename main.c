/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:30:39 by jatan             #+#    #+#             */
/*   Updated: 2023/01/05 10:32:32 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "minirt.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_data		mlx;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid arguments.\n", 2);
		return (-1);
	}
	// ft_putstr_fd(argv[1], 1);
	parse_conf_file(argv[1]);
	mlx.mlx = mlx_init();
	mlx.w = 600;
	mlx.h = 300;
	mlx.win = mlx_new_window(mlx.mlx, mlx.w, mlx.h, "miniRT");
	mlx.img = mlx_new_image(mlx.mlx, mlx.w, mlx.h);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
			&mlx.endian);
	render_image(&mlx, NULL);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 3, 1L << 1, handle_key_release, &mlx);
	mlx_loop(mlx.mlx);
}
