/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:28:53 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 15:49:17 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "hit.h"
#include <stdio.h>

/**
 * @brief To get the required values for calculation
 *
 * @param r
 * @param sp
 * @return t_sp_math
 */
t_sp_math	calc_math(t_ray *r, t_sphere sp)
{
	t_sp_math	m;

	m.oc = v_subtr(r->origin, sp.center);
	m.a = dot(r->dir, r->dir);
	m.b = dot(m.oc, r->dir);
	m.c = dot(m.oc, m.oc) - sp.radius * sp.radius;
	m.discriminant = m.b * m.b - m.a * m.c;
	return (m);
}

double	calc_dist(t_sp_math m, double min, double max)
{
	double	tmp;

	tmp = (-m.b - sqrt(m.discriminant)) / m.a;
	if ((tmp < max && tmp > min) == 0)
	{
		tmp = (-m.b + sqrt(m.discriminant)) / m.a;
		if ((tmp < max && tmp > min) == 0)
			return (-1);
	}
	return (tmp);
}

t_hit_rec	hit_spherev2(t_ray *r, double min, double max, t_object *obj)
{
	t_sphere	sp;
	t_sp_math	m;
	double		tmp;
	t_hit_rec	rec;

	sp = (t_sphere)obj->obj.sp;
	m = calc_math(r, sp);
	rec.hit = 0;
	if (m.discriminant > 0)
	{
		tmp = calc_dist(m, min, max);
		if (tmp == -1)
		{
			rec.hit = 0;
			return (rec);
		}
		rec.t = tmp;
		rec.p = point_at_parameter(*r, rec.t);
		rec.normal = v_div_d(v_subtr(rec.p, sp.center), sp.radius);
		rec.hit = 1;
	}
	return (rec);
}
