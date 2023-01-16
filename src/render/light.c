#include "minirt.h"

int  color_x_light(int color, double rgb[3])
{
  	unsigned int	mask;
  	unsigned int	r;
  	unsigned int	g;
  	unsigned int	b;
  
  	mask = 255 << 16;
  	r = rgb[0] * ((color & mask) >> 16);
  	mask >>= 8;
  	g = rgb[1] * ((color & mask) >> 8);
  	mask >>= 8;
  	b = rgb[2] * (color & mask);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
  	return ((r << 16) | (g << 8) | b);
}

int  light_itsxn(t_vec o, t_vec d, t_object *lst)
{
	double  dist;

	dist = 0;
	// while (lst)
	// {
		if (lst->id == sp)
			dist = solve_sp(o, d, lst);    
		if (dist > 0.00001 && dist < 1)
			return (0);
	// 	lst = lst->next;
	// }
	return (1);
}

//modifies the elements of the "rgb" array by adding to them 
//a coefficient multiplied by the 
//individual color channels of the "color" integer
void  multiplier(double (*rgb)[3], double coef, int color)
{
	unsigned int  mask;

	mask = 255 << 16;
	(*rgb)[0] += coef * ((color & mask) >> 16) / 255;
	mask >>= 8;
	(*rgb)[1] += coef * ((color & mask) >> 8) / 255;
	mask >>= 8;
	(*rgb)[2] += coef * (color & mask) / 255;
}

//calculate the final color of a pixel by taking into account 
//the lighting of the scene, the color of the object at that point, 
//and the object's surface normal
// vcos(itsxn->normal, direction): amt of light that reaches itsxn pt
void  calc_light(t_itsxn *itsxn, t_scene scene, t_object *lst)
{
	double		light;
	double		rgb[3];
	t_vec		dir;

	light = 0.0;
	ft_memset(rgb, 0, 3 * sizeof(double));
	multiplier(&rgb, scene.ambient.ratio, scene.ambient.color);
	while (scene.light)
	{
		dir = v_subtr(scene.light->coor, itsxn->point);
		if (light_itsxn(itsxn->point, dir, lst) && dot(itsxn->normal, dir) > 0)
		{
			light = scene.light->ratio * v_cos(itsxn->normal, dir);
			multiplier(&rgb, light, scene.light->color);
		}    
		scene.light = scene.light->next;
	}
	itsxn->color = color_x_light(itsxn->color, rgb);
}