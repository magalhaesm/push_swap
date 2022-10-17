/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:16:28 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 12:43:25 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_error(void)
{
	static int	error;

	return (&error);
}

void	set_error(int value)
{
	int	*error;

	error = get_error();
	*error = value;
}

int	error(void)
{
	int	*error;

	error = get_error();
	return (*error);
}
