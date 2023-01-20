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
static int	trace_ray(t_vec d, t_data data)
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

//rotate the vector 'd' in such a way that it points towards
//the camera's normal vector 'cam_nv'
static t_vec	cam_direction(t_vec d, t_vec cam_nv)
{
	t_vec	x_axis;
	t_vec	y_axis;
	t_vec	z_axis;
	t_vec	rotated;

	y_axis = new_vect(0, 1, 0);
	z_axis = cam_nv;
	if (cam_nv.e2 == 1)
		x_axis = new_vect(1, 0, 0);
	else if (cam_nv.e2 == -1)
		x_axis = new_vect(-1, 0, 0);
	else
		x_axis = cross(y_axis, z_axis);
	y_axis = cross(z_axis, x_axis);
	rotated.e1 = d.e1 * x_axis.e1 + d.e2 * y_axis.e1 + d.e3 * z_axis.e1;
	rotated.e2 = d.e1 * x_axis.e2 + d.e2 * y_axis.e2 + d.e3 * z_axis.e2;
	rotated.e3 = d.e1 * x_axis.e3 + d.e2 * y_axis.e3 + d.e3 * z_axis.e3;
	return (rotated);
}

//determine position of a point in 3D space (map 2d pixel to 3d scene)
static t_vec	cam_position(t_data data)
{
	double		asp_ratio;
	double		adj_fov;
	double		e1;
	double		e2;
	t_vec		point;

	e1 = (double)data.w / data.scene.res.xres;
	e2 = (double)data.h / data.scene.res.yres;
	asp_ratio = (double)(data.scene.res.xres) / (double)(data.scene.res.yres);
	adj_fov = tan((data.scene.camera.fov * M_PI / 180) / 2);
	point.e1 = (((2 * e1) - 1) * asp_ratio * adj_fov) * -1;
	point.e2 = (1 - (2 * e2)) * adj_fov;
	point.e3 = 1;
	return (point);
}

int	calc_ray(t_data data)
{
	t_vec		dir;
	int			color;

	dir = cam_position(data);
	dir = cam_direction(dir, data.scene.camera.nv);
	color = trace_ray(dir, data);
	return (color);
}
