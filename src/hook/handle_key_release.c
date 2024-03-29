/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_release.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:52:19 by jatan             #+#    #+#             */
/*   Updated: 2023/01/16 14:42:37 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

int	handle_key_release(int keycode, t_data *vars)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		exit(0);
	}
	return (0);
}
