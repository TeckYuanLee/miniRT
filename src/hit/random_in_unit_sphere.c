/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_in_unit_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:23:06 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 22:53:26 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

/**
 * @brief
 *
 * @param vec any random vec with random value
 * @return t_vec
 */
t_vec	random_in_unit_sphere(void)
{
	t_vec	p;
	t_vec	tmp;

	while (1)
	{
		tmp = (t_vec){rand_d(0), rand_d(0), rand_d(0), 0};
		// show_vec(tmp);
		p = v_subtr(v_multi_d(tmp, 2.0), (t_vec){1, 1, 1, 0});
		// printf("%f\n", length_squared(p));
		if (length_squared(p) >= 1.0)
			continue ;
		// show_vec(p);
		return (p);
	}
}

// to test the above function
// int	main(void)
// {
// 	t_vec	vec;

// 	vec = random_in_unit_sphere((t_vec){0.5, 0.03, 1, 0});
// 	show_vec(vec);
// 	ft_putstr_fd("\n", 1);
// 	vec = random_in_unit_sphere(vec);
// 	show_vec(vec);
// 	ft_putstr_fd("\n", 1);
// 	vec = random_in_unit_sphere(vec);
// 	show_vec(vec);
// 	ft_putstr_fd("\n", 1);
// 	vec = random_in_unit_sphere(vec);
// 	show_vec(vec);
// 	ft_putstr_fd("\n", 1);
// 	vec = random_in_unit_sphere(vec);
// 	show_vec(vec);
// 	ft_putstr_fd("\n", 1);
// 	return (0);
// }
