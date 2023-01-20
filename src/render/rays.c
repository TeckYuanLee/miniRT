#include "minirt.h"

//calculate the surface normal at a point of intersection,
//taking into account the type of object and
//the incoming direction of the ray.
//This information is used to compute the lighting and shading
//of the object in the scene.
static void	calc_normal(t_vec p, t_vec d, t_vec *normal, t_object *l)
{
	if (l->id == sp)
	{
		*normal = normalize(v_subtr(p, l->obj.sp.center));
		if (v_cos(d, *normal) > 0)
			*normal = v_scale(-1, *normal);
	}
	else if (v_cos(d, l->normal) > 0)
		*normal = v_scale(-1, l->normal);
	else
		*normal = l->normal;
}

//trace a ray from origin to direction in the scene and
//return color of the pixel that the ray intersects
int	trace_ray(t_vec d, t_data data)
{
	t_itsxn		itsxn;
	t_object	closest_obj;
	double		closest_itsxn;

	closest_obj.id = -1;
	closest_itsxn = INFINITY;
	ray_itsxn(d, data, &closest_obj, &closest_itsxn);
	itsxn.point = v_sum(data.scene.camera.origin, v_scale(closest_itsxn, d));
	calc_normal(itsxn.point, d, &(itsxn.normal), &closest_obj);
	if (closest_obj.id == -1)
		itsxn.color = data.scene.background;
	else
		itsxn.color = closest_obj.color;
	calc_light(&itsxn, data.scene.lights, data.scene.ambient, data.objects);
	return (itsxn.color);
}

