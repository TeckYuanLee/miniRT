/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:28:53 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 18:52:38 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	hit_sphere(t_vec center, double rad, t_ray r)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = v_subtr(r.origin, center);
	a = dot(r.dir, r.dir);
	b = 2.0 * dot(oc, r.dir);
	c = dot(oc, oc) - rad * rad;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / 2.0 * a);
}
