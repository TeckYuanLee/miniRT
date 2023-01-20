/* ************************************************************************** */
/**/
/*::::::::::: */
/* vec_math.c :+::+::+: */
/*+:+ +:+ +:+ */
/* By: jatan <jatan@student.42kl.edu.my>+#++:+ +#+*/
/*+#+#+#+#+#+ +#+ */
/* Created: 2023/01/02 13:08:13 by jatan #+##+# */
/* Updated: 2023/01/20 15:02:30 by jatan### ########.fr */
/**/
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	length(t_vec vec)
{
	return (sqrt(vec.e1 * vec.e1 + vec.e2 * vec.e2 + vec.e3 * vec.e3));
}

t_vec	unit_vec(t_vec vec)
{
	t_vec	ret;

	ret = v_div_d(vec, length(vec));
	return (ret);
}

double	dot(t_vec v1, t_vec v2)
{
	t_vec	res;

	res = v_multi(v1, v2);
	return (res.e1 + res.e2 + res.e3);
}

t_vec	cross(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.e1 = v1.e2 * v2.e3 - v1.e3 * v2.e2;
	ret.e2 = v1.e3 * v2.e1 - v1.e1 * v2.e3;
	ret.e3 = v1.e1 * v2.e2 - v1.e2 * v2.e1;
	return (ret);
}

t_vec	normalize(t_vec p)
{
	t_vec	nv;
	double	mod;

	mod = length(p);
	nv.e1 = p.e1 / mod;
	nv.e2 = p.e2 / mod;
	nv.e3 = p.e3 / mod;
	return (nv);
}

double	mod(t_vec v)
{
	return (sqrt(dot(v, v)));
}
