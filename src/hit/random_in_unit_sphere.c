/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_in_unit_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:23:06 by jatan             #+#    #+#             */
/*   Updated: 2023/01/12 14:34:13 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	random_in_unit_sphere(t_vec vec)
{
	t_vec	p;

	p = vec;
	while (1)
	{
		p = (t_vec){rand_d(p.e1 * 100, -1, 1),
			rand_d(p.e2 * 100, -1, 1), rand_d(p.e3 * 100, -1, 1), 0};
		if (length_squared(p) >= 1)
			continue ;
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
