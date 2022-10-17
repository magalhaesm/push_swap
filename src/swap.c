/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:16:34 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 11:43:40 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack);

void	swap_a(t_stack **stack)
{
	swap(stack);
	show_output("sa");
}

void	swap_b(t_stack **stack)
{
	swap(stack);
	show_output("sb");
}

void	swap_same(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	show_output("ss");
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
