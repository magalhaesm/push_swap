/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:39:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/09 13:07:40 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_from(t_stack **first, t_stack **second);

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push_from(stack_b, stack_a);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push_from(stack_a, stack_b);
	ft_putendl_fd("pb", STDOUT_FILENO);
}

static void	push_from(t_stack **first, t_stack **second)
{
	t_stack	*item;

	item = pop(first);
	if (item == NULL)
		return ;
	push(second, item);
}
