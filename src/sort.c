/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:18:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/12 20:53:48 by mdias-ma         ###   ########.fr       */
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

void	align(t_stack **stack)
{
	int		top;
	int		size;
	int		distance;
	int		increment;
	void	(*alignment)(t_stack **stack);

	increment = 1;
	size = get_size(*stack);
	top = lowest_position(*stack);
	if (top < size / 2)
	{
		distance = top;
		increment *= -1;
		alignment = rotate_a;
	}
	else
	{
		distance = top - size;
		alignment = reverse_rotate_a;
	}
	while (distance)
	{
		alignment(stack);
		distance += increment;
	}
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
