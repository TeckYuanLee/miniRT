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

t_vec	v_multi(t_vec vec1, t_vec vec2)
{
	return (new_vect(vec1.e1 * vec2.e1, vec1.e2 * vec2.e2, vec1.e3 * vec2.e3));
}

t_vec	v_div(t_vec vec1, t_vec vec2)
{
	return (new_vect(vec1.e1 / vec2.e1, vec1.e2 / vec2.e2, vec1.e3 / vec2.e3));
}

t_vec	v_sum(t_vec vec1, t_vec vec2)
{
	return (new_vect(vec1.e1 + vec2.e1, vec1.e2 + vec2.e2, vec1.e3 + vec2.e3));
}

t_vec	v_subtr(t_vec vec1, t_vec vec2)
{
	return (new_vect(vec1.e1 - vec2.e1, vec1.e2 - vec2.e2, vec1.e3 - vec2.e3));
}
