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

t_vec	v_multi_d(t_vec vec1, double d)
{
	return (new_vect(d * vec1.e1, d * vec1.e2, d * vec1.e3));
}

t_vec	v_div_d(t_vec vec1, double d)
{
	return (new_vect(vec1.e1 / d, vec1.e2 / d, vec1.e3 / d));
}
