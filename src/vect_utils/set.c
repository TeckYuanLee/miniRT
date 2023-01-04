/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:31:27 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 09:35:29 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set(t_vec *vec, enum e_vec_type c, double value)
{
	if (c == 0)
		vec->e1 = value;
	else if (c == 1)
		vec->e2 = value;
	else if (c == 2)
		vec->e3 = value;
	else
		return;
}
