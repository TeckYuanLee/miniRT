/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:29 by jatan             #+#    #+#             */
/*   Updated: 2023/01/08 13:50:21 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	error(char *message, int err_code)
{
	ft_putstr_fd(RED"Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(RESET"\n", 2);
	return (err_code);
}
