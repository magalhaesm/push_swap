/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/16 12:37:44 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack)
{
	push_bottom(stack, pop(stack));
	show_output("ra");
}

void	rotate_b(t_stack **stack)
{
	push_bottom(stack, pop(stack));
	show_output("rb");
}

void	rotate(t_stack **stack_a, t_stack **stack_b)
{
	push_bottom(stack_a, pop(stack_a));
	push_bottom(stack_b, pop(stack_b));
	show_output("rr");
}
