/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:11:44 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/12 18:14:35 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_cheapest(t_stack *stack);
static void	move_both(t_stack *temp, t_stack **stack_a, t_stack **stack_b);
static void	move_a(t_stack *temp, t_stack **stack);
static void	move_b(t_stack *temp, t_stack **stack);

void	exec_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	t_stack	*temp;

	temp = *stack_b;
	cheapest = find_cheapest(*stack_b);
	while (temp->actual_pos != cheapest)
		temp = temp->next;
	move_both(temp, stack_a, stack_b);
	move_a(temp, stack_a);
	move_b(temp, stack_b);
	push_a(stack_a, stack_b);
}

static void	move_both(t_stack *temp, t_stack **stack_a, t_stack **stack_b)
{
	while (temp->cost_a > 0 && temp->cost_b > 0)
	{
		rotate(stack_a, stack_b);
		temp->cost_a--;
		temp->cost_b--;
	}
	while (temp->cost_a < 0 && temp->cost_b < 0)
	{
		reverse_rotate(stack_a, stack_b);
		temp->cost_a++;
		temp->cost_b++;
	}
}

static int	find_cheapest(t_stack *stack)
{
	int	cost;
	int	action;
	int	cheapest;

	action = 0;
	cheapest = INT_MAX;
	while (stack != NULL)
	{
		cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
		if (cost < cheapest)
		{
			cheapest = cost;
			action = stack->actual_pos;
		}
		stack = stack->next;
	}
	return (action);
}

static void	move_a(t_stack *temp, t_stack **stack)
{
	while (temp->cost_a > 0)
	{
		rotate_a(stack);
		temp->cost_a--;
	}
	while (temp->cost_a < 0)
	{
		reverse_rotate_a(stack);
		temp->cost_a++;
	}
}

static void	move_b(t_stack *temp, t_stack **stack)
{
	while (temp->cost_b > 0)
	{
		rotate_b(stack);
		temp->cost_b--;
	}
	while (temp->cost_b < 0)
	{
		reverse_rotate_b(stack);
		temp->cost_b++;
	}
}
