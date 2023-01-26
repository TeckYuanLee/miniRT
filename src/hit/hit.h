/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:38:41 by jatan             #+#    #+#             */
/*   Updated: 2023/01/10 10:56:31 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "minirt.h"

typedef struct s_sp_math {
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
}				t_sp_math;

typedef t_hit_rec	(*t_hit_func)(t_ray *, double, double, t_object	*);

t_hit_rec	hit_spherev2(t_ray *r, double min, double max, t_object *obj);
t_hit_rec	hit_plane(t_ray *r, double min, double max, t_object *obj);
t_hit_rec	hit_cylinder(t_ray *r, double min, double max, t_object *obj);


#endif
