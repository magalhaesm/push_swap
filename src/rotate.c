/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/13 17:32:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack)
{
	push_bottom(stack, pop(stack));
	if ((*stack)->output)
		ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rotate_b(t_stack **stack)
{
	push_bottom(stack, pop(stack));
	if ((*stack)->output)
		ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rotate(t_stack **stack_a, t_stack **stack_b)
{
	push_bottom(stack_a, pop(stack_a));
	push_bottom(stack_b, pop(stack_b));
	if ((*stack_a)->output)
		ft_putendl_fd("rr", STDOUT_FILENO);
}
