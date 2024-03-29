/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_crt_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:57:34 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 18:59:10 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include <stdio.h>
#include <stdlib.h>

t_crt_func	*set_crt_funcs(void)
{
	t_crt_func	*funcs;

	funcs = (t_crt_func *)malloc(sizeof(t_crt_func) * (l + 1));
	funcs[sp] = create_sp;
	funcs[pl] = create_pl;
	funcs[cy] = create_cy;
	funcs[A] = create_ambient;
	funcs[C] = create_cam;
	funcs[R] = create_res;
	funcs[l] = create_light;
	return (funcs);
}
