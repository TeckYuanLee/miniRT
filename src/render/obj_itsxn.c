#include "minirt.h"

double	solve_sp(t_vector o, t_vector d, t_object *lst)
{
	double		disc;
 	double		x[2];
 	double		k[3];
 	t_vector	c;

	x[0] = INFINITY;
	x[1] = INFINITY;
	c = vsubtract(o, lst->obj.sp.center);
 	k[0] = dot(d, d);
 	k[1] = 2 * dot(d, c);
 	k[2] = dot(c, c) - lst->obj.sp.radius * lst->obj.sp.radius;
 	disc = k[1] * k[1] - (4 * k[0] * k[2]);
	if (disc >= 0)
    {
 	    x[0] = (-k[1] + sqrt(disc)) / (2 * k[0]);
 	    x[1] = (-k[1] - sqrt(disc)) / (2 * k[0]);
    }
 	if (x[0] > 0.00001 && x[0] < INFINITY && x[0] < x[1])
  		return (x[0]);
 	if (x[1] > 0.00001 && x[1] < INFINITY && x[1] < x[0])
		return (x[1]);
  	return (INFINITY);
}

void	ray_itsxn(t_vec d, t_data data, t_object *closest_obj, double *closest_itsxn)
{
 	double dist;

	dist = 0;
	while (data.objects)
	{
  		if (((t_object *)(data.objects->content))->id == sp)
   			dist = solve_sp(data.scene.camera.origin, d, data.objects);
  		if (dist > 0.00001 && dist < *closest_itsxn)
  		{
   			*closest_obj = *((t_object)(data.objects->content));
   			*closest_itsxn = dist;
  		}
  		data.objects = data.objects->next;
 	}
}
