/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 11:42:21 by mdias-ma         ###   ########.fr       */
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

void	rotate(t_stack **a, t_stack **b)
{
	push_bottom(a, pop(a));
	push_bottom(b, pop(b));
	show_output("rr");
}
