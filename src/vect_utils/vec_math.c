/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:08:13 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 09:35:29 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	length(t_vec vec)
{
	return (sqrt(vec.e1 * vec.e1 + vec.e2 * vec.e2 + vec.e3 * vec.e3));
}

t_vec	unit_vec(t_vec vec)
{
	t_vec	ret;

	ret = v_div_d(vec, length(vec));
	return (ret);
}
