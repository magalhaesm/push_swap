/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:02:51 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/17 11:41:49 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **a, t_stack **b);

int	main(int argc, char **argv)
{
	int		size;
	int		*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	size = argc - 1;
	if (size <= 1)
		return (EXIT_SUCCESS);
	numbers = parse_int(size, argv + 1);
	if (numbers == NULL)
		err_exit();
	stack_a = init_stack(numbers, size);
	if (stack_a == NULL)
		err_exit();
	stack_b = NULL;
	create_index(&stack_a, numbers, size);
	push_swap(&stack_a, &stack_b);
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	free(numbers);
	return (EXIT_SUCCESS);
}

static void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	set_output(TRUE);
	if (is_sorted(*a))
		return ;
	size = get_size(*a);
	if (size == 2)
		swap_a(a);
	else if (size == 3)
		sort_three(a);
	else
		sort_all(a, b);
}
