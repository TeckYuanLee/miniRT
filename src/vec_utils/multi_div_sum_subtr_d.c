/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_multi_v_div_v_sum_v_subtr_d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:31:20 by jatan             #+#    #+#             */
/*   Updated: 2023/01/02 12:52:24 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	v_multi_d(t_vec v, double d)
{
	return ((t_vec){v.e1 * d, v.e2 * d, v.e3 * d, 0});
}

t_vec	v_div_d(t_vec v, double d)
{
	return ((t_vec){v.e1 / d, v.e2 / d, v.e3 / d, 0});
}
