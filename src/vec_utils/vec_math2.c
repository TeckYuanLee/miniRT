#include "minirt.h"
#include <math.h>

double		distance(t_vec p1, t_vec p2)
{
	double d;

	d = sqrt(pow(p2.e1 - p1.e1, 2) + pow(p2.e2 - p1.e2, 2) + pow(p2.e3 - p1.e3, 2));
	return (d);
}