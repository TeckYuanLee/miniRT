#include <mlx.h>
#include "minirt.h"

#define WIDTH 1000
#define HEIGHT 800

int main(void)
{
	t_data mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Hello world!");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
								 &mlx.endian);
	put_pixel(&mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 3, 1L << 1, handle_key_release, &mlx);
	mlx_loop(mlx.mlx);
}
