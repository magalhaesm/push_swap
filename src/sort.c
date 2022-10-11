/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:18:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/11 13:55:32 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_position(t_stack *stack);

void	sort_few(t_stack **stack)
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
	sort_few(stack);
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
