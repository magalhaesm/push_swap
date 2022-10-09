/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:39:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/08 17:44:17 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	binary_search(int *arr, int size, int nb);
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

static int	binary_search(int *arr, int size, int nb)
{
	int	start;
	int	mid;
	int	end;

	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (nb < arr[mid])
			end = mid - 1;
		else
		{
			if (nb > arr[mid])
				start = mid + 1;
			else
				return (mid);
		}
	}
	return (-1);
}
