/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:02:44 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 12:47:24 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_atoi(char *str);
static int	check_int(char **input, int size);
static void	check_duplicates(int *numbers, int size);

int	*parse_int(int size, char **input)
{
	int	n;
	int	nbr;
	int	*numbers;

	n = size;
	if (check_int(input, size) == FALSE)
		err_exit(EXIT_FAILURE);
	numbers = malloc(n * sizeof(nbr));
	if (numbers == NULL)
		return (NULL);
	while (n--)
	{
		nbr = check_atoi(input[n]);
		numbers[n] = nbr;
	}
	check_duplicates(numbers, size);
	if (error())
	{
		free(numbers);
		err_exit(EXIT_FAILURE);
	}
	return (numbers);
}

static int	check_int(char **input, int size)
{
	char	*str;

	while (size--)
	{
		str = input[size];
		if (*str == '\0')
			return (FALSE);
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
		{
			if (ft_isdigit(*str) == FALSE)
				return (FALSE);
			str++;
		}
	}
	return (TRUE);
}

static void	check_duplicates(int *numbers, int size)
{
	int	eval;
	int	next;

	eval = 0;
	while (eval < size)
	{
		next = eval + 1;
		while (next < size)
		{
			if (numbers[eval] == numbers[next])
			{
				set_error(TRUE);
				break ;
			}
			next++;
		}
		eval++;
	}
}

static int	check_atoi(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		set_error(TRUE);
	return (nbr);
}
