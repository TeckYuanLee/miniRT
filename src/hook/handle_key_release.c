#include "minirt.h"
#include <stdio.h>
#include <stdlib.h>

int handle_key_release(int keycode, t_data *vars)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
