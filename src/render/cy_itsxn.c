/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_itsxn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:58:53 by telee             #+#    #+#             */
/*   Updated: 2023/02/06 11:59:00 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief calculate intersection to the cylinder caps
 *
 * @param o ray origin
 * @param d ray direction
 * @param lst the intersected object
 * @return the distance as double
 */
static double	cy_caps(t_vec o, t_vec d, t_cylinder *cy)
{
	double	c[2];
	t_vec	c_it[2];
	t_vec	c_bottom;

	c_bottom = v_sum(cy->center, v_multi_d(cy->nv, cy->height));
	c[0] = solve_pl(o, d, cy->center, cy->nv);
	c[1] = solve_pl(o, d, c_bottom, cy->nv);
	if (c[0] < INFINITY || c[1] < INFINITY)
	{
		c_it[0] = v_sum(o, v_multi_d(d, c[0]));
		c_it[1] = v_sum(o, v_multi_d(d, c[1]));
		if ((c[0] < INFINITY && distance(c_it[0], cy->center) <= cy->radius)
			&& (c[1] < INFINITY && distance(c_it[1], c_bottom) <= cy->radius))
		{
			if (c[0] < c[1])
				return (c[0]);
			return (c[1]);
		}
		else if (c[0] < INFINITY && distance(c_it[0], cy->center) <= cy->radius)
			return (c[0]);
		else if (c[1] < INFINITY && distance(c_it[1], c_bottom) <= cy->radius)
			return (c[1]);
	}
	return (INFINITY);
}

/**
 * @brief check if point of intersection is within the range of cylinder
 *
 * @param x store intersection distance
 * @param dist store closest intersection to cylinder ends
 * @param lst the intersected object
 */
static void	get_closest_itsxn(double x[2], double dist[2], t_object *lst)
{
	if ((dist[0] >= 0 && dist[0] <= lst->obj.cy.height && x[0] > 0.00001)
		&& (dist[1] >= 0 && dist[1] <= lst->obj.cy.height && x[1] > 0.00001))
	{
		if (x[0] > x[1])
		{
			dist[0] = dist[1];
			x[0] = x[1];
		}
	}
	else if (dist[1] >= 0 && dist[1] <= lst->obj.cy.height && x[1] > 0.00001)
	{
		dist[0] = dist[1];
		x[0] = x[1];
	}
}

/**
 * @brief calculate distance of intersection to center of each cylinder ends/
 *
 *
 * @param o ray origin
 * @param d ray direction
 * @param nv adjusted cylinder normal
 * @param lst the intersected object
 * @param x store intersection distance
 */
static t_vec	open_finite_cy(t_vec o, t_vec d, t_object *lst, double x[2])
{
	double	dist[2];
	t_vec	oc;
	t_vec	point;

	oc = v_subtr(lst->obj.cy.center, o);
	dist[0] = dot(lst->obj.cy.nv, v_subtr(v_multi_d(d, x[0]), oc));
	dist[1] = dot(lst->obj.cy.nv, v_subtr(v_multi_d(d, x[1]), oc));
	if ((dist[0] >= 0 && dist[0] <= lst->obj.cy.height && x[0] > 0.00001)
		|| (dist[1] >= 0 && dist[1] <= lst->obj.cy.height && x[1] > 0.00001))
	{
		get_closest_itsxn(x, dist, lst);
		point = v_subtr(v_multi_d(d, x[0]), v_multi_d(lst->obj.cy.nv, dist[0]));
		return (normalize(v_subtr(point, oc)));
	}
	else
		x[0] = INFINITY;
	return ((t_vec){0, 0, 0, 0});
}

/**
 * @brief find intersection to an infinite cylinder with no caps
 *
 * @param x store intersection distance
 * @param o ray origin
 * @param d ray direction
 * @param lst the intersected object
 * @return true or false
 */
static int	infinite_cy(double x[2], t_vec o, t_vec d, t_object *lst)
{
	t_vec	ocd;
	t_vec	dir;
	t_vec	oc;
	double	k[3];
	double	disc;

	oc = v_subtr(o, lst->obj.cy.center);
	dir = v_subtr(d, v_multi_d(lst->obj.cy.nv, dot(d, lst->obj.cy.nv)));
	ocd = v_subtr(oc, v_multi_d(lst->obj.cy.nv, dot(oc, lst->obj.cy.nv)));
	k[0] = dot(dir, dir);
	k[1] = 2 * dot(dir, ocd);
	k[2] = dot(ocd, ocd) - lst->obj.cy.radius * lst->obj.cy.radius;
	disc = k[1] * k[1] - (4 * k[0] * k[2]);
	if (disc >= 0)
	{
		x[0] = (-k[1] + sqrt(disc)) / (2 * k[0]);
		x[1] = (-k[1] - sqrt(disc)) / (2 * k[0]);
	}
	if ((x[0] > 0.00001 && x[0] < INFINITY)
		|| (x[1] > 0.00001 && x[1] < INFINITY))
		return (1);
	return (0);
}

/**
 * @brief find closest intersection to cylinder body/caps
 *
 * @param o ray origin
 * @param d ray direction
 * @param lst the intersected object
 * @return the distance as double
 */
double	solve_cy(t_vec o, t_vec d, t_object *lst)
{
	t_vec	adj_cy_nv;
	double	x[2];

	x[0] = INFINITY;
	x[1] = INFINITY;
	if (infinite_cy(x, o, d, lst))
		adj_cy_nv = open_finite_cy(o, d, lst, x);
	x[1] = cy_caps(o, d, &lst->obj.cy);
	if (x[0] < INFINITY || x[1] < INFINITY)
	{
		if (x[0] < x[1])
		{
			lst->normal = adj_cy_nv;
			return (x[0]);
		}
		lst->normal = lst->obj.cy.nv;
		return (x[1]);
	}
	return (INFINITY);
}
