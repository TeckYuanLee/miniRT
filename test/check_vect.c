/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:01:53 by jatan             #+#    #+#             */
/*   Updated: 2023/01/03 23:12:05 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	check_vect_propt(double check, double ans)
{
	if (check != ans)
		printf("\n❌ failed: should be %f, but got %f\n", ans, check);
	else
		printf("✅ correct!  ");
}

void	check_vect(t_vector check, t_vector ans)
{
	check_vect_propt(check.e1, ans.e1);
	check_vect_propt(check.e2, ans.e2);
	check_vect_propt(check.e3, ans.e3);
}

void	run_check_vect(void)
{
	t_vector	vect;

	set(&vect, x, 1.0);
	set(&vect, y, 2.0);
	set(&vect, z, 3.0);
	check_vect(vect, new_vect(1.0, 2.0, 3.0));

	vect = v_multi(new_vect(1, 2, 3), new_vect(2.0, 2.0, 2.0));
	check_vect(vect, new_vect(2.0, 4.0, 6.0));

	vect = v_div(new_vect(2, 4, 6), new_vect(3.0, 3.0, 3.0));
	check_vect(vect, new_vect(2.0 / 3, 4.0 / 3, 6.0 / 3));

	vect = v_sum(new_vect(2, 4, 6), new_vect(4.0, 5.0, 6.0));
	check_vect(vect, new_vect(2.0 + 4, 4.0 + 5, 6.0 + 6));

	vect = v_subtr(new_vect(2, 4, 6), new_vect(4.0, 5.0, 6.0));
	check_vect(vect, new_vect(2.0 - 4, 4.0 - 5, 6.0 - 6));


	vect = v_multi(new_vect(1, 2, 3), new_vect(2.0, 2.0, 2.0));
	check_vect(vect, new_vect(2.0, 4.0, 6.0));

	vect = v_div(new_vect(2, 4, 6), new_vect(3.0, 3.0, 3.0));
	check_vect(vect, new_vect(2.0 / 3, 4.0 / 3, 6.0 / 3));

	vect = v_sum(new_vect(2, 4, 6), new_vect(4.0, 5.0, 6.0));
	check_vect(vect, new_vect(2.0 + 4, 4.0 + 5, 6.0 + 6));

	vect = v_multi_d(new_vect(2, 4, 6), 4);
	check_vect(vect, new_vect(2.0 * 4, 4.0 * 4, 6.0 * 4));

	vect = v_div_d(new_vect(2, 4, 6), 4);
	check_vect(vect, new_vect(2.0 / 4, 4.0 / 4, 6.0 / 4));
}
