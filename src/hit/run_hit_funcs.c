/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_hit_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:56:44 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 15:25:25 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include <stdlib.h>

t_hit_rec	run_hit_funcs(t_ray r, double min, double max, t_object *obj)
{
	t_hit_func	funcs[3];

	funcs[sp] = hit_spherev2;
	funcs[pl] = NULL;
	funcs[cy] = NULL;
	return (funcs[(int)obj->id](r, min, max, obj));
}
