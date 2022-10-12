/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:18:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/12 19:10:12 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_position(t_stack *stack);

void	sort_three(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = highest_position(*stack);
	if (highest == 0)
		rotate_a(stack);
	else if (highest == 1)
		reverse_rotate_a(stack);
	else
		swap_a(stack);
	sort_three(stack);
}

int	lowest_position(t_stack *stack)
{
	int		min;
	int		index;
	t_stack	*temp;

	min = INT_MAX;
	index = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	while (stack->index != min)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

static int	highest_position(t_stack *stack)
{
	int		max;
	int		index;
	t_stack	*temp;

	max = 0;
	index = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while (stack->index != max)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}
