/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:11:33 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 15:42:53 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	show_vec(t_vec vec)
{
	printf("e1: %f\te2: %f\te3: %f\n", vec.e1, vec.e2, vec.e3);
}
