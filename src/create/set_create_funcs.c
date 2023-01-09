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

#include <stdlib.h>

t_crt_func	*set_crt_funcs(void)
{
	t_crt_func	*funcs;

	funcs = (t_crt_func *)malloc(sizeof(t_crt_func) * (L + 1));
	funcs[sp] = create_sp;
	funcs[pl] = NULL;
	funcs[cy] = NULL;
	funcs[A] = create_ambient;
	funcs[C] = create_cam;
	funcs[L] = create_light;

	return (funcs);
}
