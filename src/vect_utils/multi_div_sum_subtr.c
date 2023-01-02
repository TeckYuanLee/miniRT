/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_div_sum_subtr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:31:20 by jatan             #+#    #+#             */
/*   Updated: 2023/01/02 12:37:06 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	multi(t_vector vec1, t_vector vec2)
{
	return (new_vect(vec1.e1 * vec2.e1, vec1.e2 * vec2.e2, vec1.e3 * vec2.e3));
}

t_vector	div(t_vector vec1, t_vector vec2)
{
	return (new_vect(vec1.e1 / vec2.e1, vec1.e2 / vec2.e2, vec1.e3 / vec2.e3));
}

t_vector	sum(t_vector vec1, t_vector vec2)
{
	return (new_vect(vec1.e1 + vec2.e1, vec1.e2 + vec2.e2, vec1.e3 + vec2.e3));
}

t_vector	subtr(t_vector vec1, t_vector vec2)
{
	return (new_vect(vec1.e1 - vec2.e1, vec1.e2 - vec2.e2, vec1.e3 - vec2.e3));
}
