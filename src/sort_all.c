/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:01:38 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 11:43:17 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define DUMP_LIMIT 3

static int	highest_index(t_stack *stack);
static void	dump_a(t_stack **a, t_stack **b);
static void	set_position(t_stack **stack);
static void	set_target(t_stack **a, t_stack **b);

void	sort_all(t_stack **a, t_stack **b)
{
	dump_a(a, b);
	sort_three(a);
	while (*b)
	{
		set_position(a);
		set_position(b);
		set_target(a, b);
		set_costs(a, b);
		exec_cheapest(a, b);
	}
	align(a);
}

static void	set_target(t_stack **a, t_stack **b)
{
	int		highest;
	int		closest_max;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = *b;
	highest = highest_index(*a);
	while (temp_b != NULL)
	{
		temp_a = *a;
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
			temp_b->target_pos = lowest_position(*a);
		temp_b = temp_b->next;
	}
}

static void	set_position(t_stack **stack)
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

static void	dump_a(t_stack **a, t_stack **b)
{
	int	size;
	int	counter;
	int	low_half;

	size = get_size(*a);
	counter = size - 1;
	low_half = size / 2;
	while (counter > DUMP_LIMIT)
	{
		if ((*a)->index < low_half)
			push_b(a, b);
		else
			rotate_a(a);
		counter--;
	}
	counter = get_size(*a) - DUMP_LIMIT;
	while (counter--)
		push_b(a, b);
}
