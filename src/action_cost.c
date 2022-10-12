/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:47:57 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/12 14:17:56 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_cost(t_stack **stack);

void	set_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	get_cost(stack_a);
	get_cost(stack_b);
	temp_b = *stack_b;
	while (temp_b != NULL)
	{
		temp_a = *stack_a;
		while (temp_b->target_pos != temp_a->actual_pos)
			temp_a = temp_a->next;
		temp_b->cost_a = temp_a->cost_b;
		temp_b = temp_b->next;
	}
}

static void	get_cost(t_stack **stack)
{
	int		mid;
	int		size;
	t_stack	*temp;

	temp = *stack;
	size = get_size(*stack);
	mid = size / 2;
	while (temp != NULL)
	{
		if (temp->actual_pos <= mid)
			temp->cost_b = temp->actual_pos;
		else
			temp->cost_b = temp->actual_pos - size;
		temp = temp->next;
	}
}
