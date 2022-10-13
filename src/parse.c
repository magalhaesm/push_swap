/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:02:44 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/13 18:39:41 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_atoi(char *str, int *error);
static int	has_duplicates(int *numbers, int size);
static int	check_int(char **input, int size);

int	*parse_int(int size, char **input)
{
	int	n;
	int	nbr;
	int	error;
	int	*numbers;

	n = size;
	error = FALSE;
	if (check_int(input, size) == FALSE)
		return (NULL);
	numbers = malloc(n * sizeof(nbr));
	if (numbers == NULL)
		return (NULL);
	while (n--)
	{
		nbr = check_atoi(input[n], &error);
		if (error)
			break ;
		numbers[n] = nbr;
	}
	if (error || has_duplicates(numbers, size))
	{
		free(numbers);
		return (NULL);
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

static int	has_duplicates(int *numbers, int size)
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
				return (TRUE);
			next++;
		}
		eval++;
	}
	return (FALSE);
}

static int	check_atoi(char *str, int *error)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		*error = TRUE;
	return (nbr);
}
