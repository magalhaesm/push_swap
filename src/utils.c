/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:10:02 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 11:53:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c);

void	err_exit(int code)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(code);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	total;

	sign = 1;
	total = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= (-1);
		nptr++;
	}
	while (ft_isdigit(*nptr))
		total = *(nptr++) - '0' + (total * 10);
	return (total * sign);
}

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}
