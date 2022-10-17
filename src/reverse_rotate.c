/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:33:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 11:42:05 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack)
{
	push(stack, pop_bottom(stack));
	show_output("rra");
}

void	reverse_rotate_b(t_stack **stack)
{
	push(stack, pop_bottom(stack));
	show_output("rrb");
}

void	reverse_rotate(t_stack **a, t_stack **b)
{
	push(a, pop_bottom(a));
	push(b, pop_bottom(b));
	show_output("rrr");
}
