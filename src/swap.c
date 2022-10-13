/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:16:34 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/13 17:32:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack);

void	swap_a(t_stack **stack)
{
	swap(stack);
	if ((*stack)->output)
		ft_putendl_fd("sa", STDOUT_FILENO);
}

void	swap_b(t_stack **stack)
{
	swap(stack);
	if ((*stack)->output)
		ft_putendl_fd("sb", STDOUT_FILENO);
}

void	swap_same(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	if ((*stack_a)->output)
		ft_putendl_fd("ss", STDOUT_FILENO);
}

static void	swap(t_stack **stack)
{
	t_stack	*item1;
	t_stack	*item2;

	item1 = pop(stack);
	item2 = pop(stack);
	push(stack, item1);
	push(stack, item2);
}
