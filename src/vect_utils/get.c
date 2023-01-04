/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:19:25 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 09:35:29 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get(t_vec *vec, enum e_vec_type c)
{
	if (c == 0)
		return (vec->e1);
	else if (c == 1)
		return (vec->e2);
	else if (c == 2)
		return (vec->e3);
	else
		return (-1);
}
