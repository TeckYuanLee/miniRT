/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_at_parameter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:00:56 by jatan             #+#    #+#             */
/*   Updated: 2023/01/04 10:02:47 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

t_vec	point_at_parameter(t_ray ray, double t)
{
	return (v_sum(ray.origin, v_multi_d(ray.dir, t)));
}
