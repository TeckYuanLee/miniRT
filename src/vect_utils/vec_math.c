/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:08:13 by jatan             #+#    #+#             */
/*   Updated: 2023/01/02 13:41:40 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	length(t_vector vec)
{
	return (sqrt(vec.e1 * vec.e1 + vec.e2 * vec.e2 + vec.e3 * vec.e3));
}

t_vector	unit_vector(t_vector vec)
{
	return (v_div_d(vec, length(vec)));
}
