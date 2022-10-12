/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:01:38 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/12 19:01:29 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define DUMP_LIMIT 3

static int	highest_index(t_stack *stack);
static void	dump_a(t_stack **stack_a, t_stack **stack_b);
static void	set_actual_position(t_stack **stack);
static void	set_target_position(t_stack **stack_a, t_stack **stack_b);

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	dump_a(stack_a, stack_b);
	sort_few(stack_a);
	set_actual_position(stack_a);
	set_actual_position(stack_b);
	set_target_position(stack_a, stack_b);
	set_cost(stack_a, stack_b);
}

static void	set_target_position(t_stack **stack_a, t_stack **stack_b)
{
	int		highest;
	int		closest_max;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = *stack_b;
	highest = highest_index(*stack_a);
	while (temp_b != NULL)
	{
		temp_a = *stack_a;
		closest_max = highest;
		while (temp_a != NULL)
		{
			if (temp_b->index < temp_a->index && temp_a->index <= closest_max)
			{
				temp_b->target_pos = temp_a->actual_pos;
				closest_max = temp_a->index;
			}
			temp_a = temp_a->next;
		}
		if (temp_b->index > highest)
			temp_b->target_pos = lowest_position(*stack_a);
		temp_b = temp_b->next;
	}
}

static void	set_actual_position(t_stack **stack)
{
	int		pos;
	t_stack	*temp;

	pos = 0;
	temp = *stack;
	while (temp != NULL)
	{
		temp->actual_pos = pos;
		temp = temp->next;
		pos++;
	}
}

static int	highest_index(t_stack *stack)
{
	int		max;
	t_stack	*temp;

	max = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

static void	dump_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	counter;
	int	low_half;

	size = get_size(*stack_a);
	counter = size - 1;
	low_half = size / 2;
	while (counter > DUMP_LIMIT)
	{
		if ((*stack_a)->index < low_half)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		counter--;
	}
	counter = get_size(*stack_a) - DUMP_LIMIT;
	while (counter--)
		push_b(stack_a, stack_b);
}
