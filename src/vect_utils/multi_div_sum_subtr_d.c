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

t_vector	v_multi_d(t_vector vec1, double d)
{
	return (new_vect(vec1.e1 * d, vec1.e2 * d, vec1.e3 * d));
}

t_vector	v_div_d(t_vector vec1, double d)
{
	return (new_vect(vec1.e1 / d, vec1.e2 / d, vec1.e3 / d));
}
