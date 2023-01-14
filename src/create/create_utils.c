/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:41:43 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 18:37:22 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "stdio.h"

/**
 * @brief Convert a string "0.0,0.1,0.2" to a t_vec
 *
 * @param conf the string in format "0.0,0.1,0.2"
 * @return t_vec
 */
int	convrt_to_int(const char *conf)
{
	char	**arr;
	// t_vec	ret;
	int	e1;
	int	e2;
	int	e3;

	arr = ft_split(conf, ',');
	e1 = 0;
	e2 = 0;
	e3 = 0;
	e1 |= ft_atoi(arr[0]);
	e1 <<= 16;
	e2 |= ft_atoi(arr[1]);
	e2 <<= 8;
	e3 |= ft_atoi(arr[2]);
	// printf("creating vec x:%f, y:%f, z:%f\n", ret.e1, ret.e2, ret.e3);
	ft_free_array(arr);
	free(arr);
	return (e1 | e2 | e3);
}

t_vec	convrt_to_vec(const char *conf)
{
	char	**arr;
	t_vec	ret;

	arr = ft_split(conf, ',');
	ret.e1 = ft_atod(arr[0]);
	ret.e2 = ft_atod(arr[1]);
	ret.e3 = ft_atod(arr[2]);
	printf("creating vec x:%f, y:%f, z:%f\n", ret.e1, ret.e2, ret.e3);
	ft_free_array(arr);
	free(arr);
	return (ret);
}

/**
 * @brief To check if the string is a correct vector format, "0.0,0.1,0.2"
 *
 * @param conf
 * @return 0 if true, 1 if false
 */
int	is_vec_format(const char *conf)
{
	char	**tmp;
	int		i;

	tmp = ft_split(conf, ',');
	i = 0;
	while (tmp[i])
		i++;
	ft_free_array(tmp);
	free(tmp);
	if (i == 3)
		return (0);
	else
		return (1);
}
