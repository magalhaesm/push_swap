/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:01:41 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 13:21:32 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_item(int value);

t_stack	*init_stack(int *input, int size)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = NULL;
	while (size--)
	{
		if (stack == NULL)
			stack = new_item(input[size]);
		else
		{
			tmp = new_item(input[size]);
			if (tmp == NULL)
				break ;
			tmp->next = stack;
			stack = tmp;
		}
	}
	if (error())
	{
		destroy_stack(&stack);
		err_exit(EXIT_FAILURE);
	}
	return (stack);
}

static t_stack	*new_item(int value)
{
	t_stack	*number;

	number = malloc(sizeof(*number));
	if (number == NULL)
	{
		set_error(TRUE);
		return (NULL);
	}
	number->value = value;
	number->index = -1;
	number->actual_pos = -1;
	number->target_pos = -1;
	number->next = NULL;
	return (number);
}

int	is_sorted(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack != NULL)
	{
		if (index > stack->index)
			return (FALSE);
		index = stack->index;
		stack = stack->next;
	}
	return (TRUE);
}

int	get_size(t_stack *stack)
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

void	destroy_stack(t_stack **top)
{
	t_stack	*tmp;

	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
}
