/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:33:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/09 17:36:33 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack)
{
	push(stack, pop_bottom(stack));
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	reverse_rotate_b(t_stack **stack)
{
	push(stack, pop_bottom(stack));
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, pop_bottom(stack_a));
	push(stack_b, pop_bottom(stack_b));
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
