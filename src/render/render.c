#include "minirt.h"

void  render_scene(t_data data)
{
  	int		color;

  	// rt.data.bgr = 0x202020;
	data.scene.background = 0x202020;
	// rt.j = 0;
  	// while (rt.j < rt.data.yres)
  	// {
  	// 	rt.i = 0;
  	//  	while (rt.i < rt.data.xres)
  	//  	{
	// 		color = calc_ray(rt);
  	//   		rt.mlx.addr[rt.j * rt.data.xres + rt.i] = color;
  	//   		rt.i++;
  	//  	}
  	//   	printf("\rRendering scene... [%.2f%%]", (double)100 * rt.j / rt.data.yres);
  	//  	rt.j++;
  	// }
  	// printf("\rRendering scene...   [100%%]\n");
	data.h = 0;
	while (data.h < data.yres)
	{
		data.w = 0;
 		while (data.w < data.xres)
 		{
			color = calc_ray(data);
  			data.img.addr[data.h * data.xres + data.w] = color;
  			data.w++;
 		}
  		printf("\rRendering scene... [%.2f%%]", (double)100 * data.h / data.yres);
 		data.h++;
	}
	printf("\rRendering scene...   [100%%]");
}
