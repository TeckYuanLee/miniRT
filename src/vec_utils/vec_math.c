/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:08:13 by jatan             #+#    #+#             */
/*   Updated: 2023/02/06 12:07:50 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	length(t_vec vec)
{
	return (sqrt(dot(vec, vec)));
}

double	dot(t_vec v1, t_vec v2)
{
	t_vec	res;

	res = v_multi(v1, v2);
	return (res.e1 + res.e2 + res.e3);
}

t_vec	cross(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.e1 = v1.e2 * v2.e3 - v1.e3 * v2.e2;
	ret.e2 = v1.e3 * v2.e1 - v1.e1 * v2.e3;
	ret.e3 = v1.e1 * v2.e2 - v1.e2 * v2.e1;
	return (ret);
}

t_vec	normalize(t_vec p)
{
	return (v_div_d(p, length(p)));
}

double	distance(t_vec p1, t_vec p2)
{
	double	d;

	d = sqrt(dot(p1, p2));
	return (d);
}
