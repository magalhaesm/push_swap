/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:46:26 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 11:38:42 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_output(void)
{
	static int	output;

	return (&output);
}

void	show_output(char *action)
{
	if (has_output())
		ft_putendl_fd(action, STDOUT_FILENO);
}

int	set_output(int value)
{
	int	*output;

	output = get_output();
	*output = value;
	return (*output);
}

int	has_output(void)
{
	int	*output;

	output = get_output();
	return (*output);
}
