/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:29:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/09 12:52:12 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, t_stack *item)
{
	item->next = *stack;
	*stack = item;
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	*stack = (*stack)->next;
	return (temp);
}

void	push_bottom(t_stack **stack, t_stack *item)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	item->next = NULL;
	temp->next = item;
}

t_stack	*pop_bottom(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	int		size;

	size = stack_size(*stack) - 2;
	temp = *stack;
	while (size--)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	return (last);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
