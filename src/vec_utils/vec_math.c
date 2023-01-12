/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:08:13 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 12:29:27 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	length(t_vec vec)
{
	return (sqrt(length_squared(vec)));
}

double	length_squared(t_vec vec)
{
	return (vec.e1 * vec.e1 + vec.e2 * vec.e2 + vec.e3 * vec.e3);
}

t_vec	unit_vec(t_vec vec)
{
	t_vec	ret;

	ret = v_div_d(vec, length(vec));
	return (ret);
}

double	dot(t_vec v1, t_vec v2)
{
	t_vec	res;

	res = v_multi(v1, v2);
	return (res.e1 + res.e2 + res.e3);
}
