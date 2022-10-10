/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:39:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/10 11:31:42 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	binary_search(int *array, int size, int nbr);
static void	selection_sort(int *input, int size);

void	create_index(t_stack **stack, int *input, int size)
{
	t_stack	*tmp;

	tmp = *stack;
	selection_sort(input, size);
	while (tmp != NULL)
	{
		tmp->index = binary_search(input, size, tmp->value);
		tmp = tmp->next;
	}
}

static void	selection_sort(int *input, int size)
{
	int	i;
	int	j;
	int	smaller;
	int	swap;

	i = 0;
	while (i < size - 1)
	{
		smaller = i;
		j = i + 1;
		while (j < size)
		{
			if (input[j] < input[smaller])
				smaller = j;
			j++;
		}
		if (i != smaller)
		{
			swap = input[i];
			input[i] = input[smaller];
			input[smaller] = swap;
		}
		i++;
	}
}

static int	binary_search(int *array, int size, int nbr)
{
	int	low;
	int	mid;
	int	high;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (nbr < array[mid])
			high = mid - 1;
		else
		{
			if (nbr > array[mid])
				low = mid + 1;
			else
				return (mid);
		}
	}
	return (-1);
}
