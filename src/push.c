/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:39:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/09 13:20:45 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, pop(stack_b));
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, pop(stack_a));
	ft_putendl_fd("pb", STDOUT_FILENO);
}
