/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_multi_v_div_v_sum_v_subtr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:31:20 by jatan             #+#    #+#             */
/*   Updated: 2023/01/02 12:37:06 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	v_multi(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.e1 * v2.e1, v1.e2 * v2.e2, v1.e3 * v2.e3, 0});
}

t_vec	v_div(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.e1 / v2.e1, v1.e2 / v2.e2, v1.e3 / v2.e3, 0});
}

t_vec	v_sum(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.e1 + v2.e1, v1.e2 + v2.e2, v1.e3 + v2.e3, 0});
}

t_vec	v_subtr(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.e1 - v2.e1, v1.e2 - v2.e2, v1.e3 - v2.e3, 0});
}

double	v_cos(t_vec a, t_vec b)
{
	return (dot(a, b) / (length(a) * length(b)));
}
