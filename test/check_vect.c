/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:01:53 by jatan             #+#    #+#             */
/*   Updated: 2023/01/20 15:27:16 by jatan            ###   ########.fr       */
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

void	check_vect(t_vec check, t_vec ans)
{
	check_vect_propt(check.e1, ans.e1);
	check_vect_propt(check.e2, ans.e2);
	check_vect_propt(check.e3, ans.e3);
}

void	run_check_vect(void)
{
	t_vec	vect;

	vect = (t_vec){1.0, 2.0, 3.0, 0};
	check_vect(vect, (t_vec){1.0, 2.0, 3.0});

	vect = v_multi((t_vec){1, 2, 3, 0}, (t_vec){2.0, 2.0, 2.0, 0});
	check_vect(vect, (t_vec){2.0, 4.0, 6.0, 0});

	vect = v_div((t_vec){2, 4, 6, 0}, (t_vec){3.0, 3.0, 3.0, 0});
	check_vect(vect, (t_vec){2.0 / 3, 4.0 / 3, 6.0 / 3, 0});

	vect = v_sum((t_vec){2, 4, 6, 0}, (t_vec){4.0, 5.0, 6.0, 0});
	check_vect(vect, (t_vec){2.0 + 4, 4.0 + 5, 6.0 + 6, 0});

	vect = v_subtr((t_vec){2, 4, 6, 0}, (t_vec){4.0, 5.0, 6.0, 0});
	check_vect(vect, (t_vec){2.0 - 4, 4.0 - 5, 6.0 - 6, 0});


	vect = v_multi((t_vec){1, 2, 3, 0}, (t_vec){2.0, 2.0, 2.0, 0});
	check_vect(vect, (t_vec){2.0, 4.0, 6.0, 0});

	vect = v_div((t_vec){2, 4, 6, 0}, (t_vec){3.0, 3.0, 3.0, 0});
	check_vect(vect, (t_vec){2.0 / 3, 4.0 / 3, 6.0 / 3, 0});

	vect = v_sum((t_vec){2, 4, 6, 0}, (t_vec){4.0, 5.0, 6.0, 0});
	check_vect(vect, (t_vec){2.0 + 4, 4.0 + 5, 6.0 + 6, 0});

	vect = v_multi_d((t_vec){2, 4, 6, 0}, 4);
	check_vect(vect, (t_vec){2.0 * 4, 4.0 * 4, 6.0 * 4, 0});

	vect = v_div_d((t_vec){2, 4, 6, 0}, 4);
	check_vect(vect, (t_vec){2.0 / 4, 4.0 / 4, 6.0 / 4, 0});
}
