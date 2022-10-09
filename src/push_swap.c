/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:02:51 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/09 17:44:15 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	int		*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	size = argc - 1;
	numbers = parse_int(size, argv + 1);
	if (numbers == NULL)
		err_exit();
	stack_a = init_stack(numbers, size);
	if (stack_a == NULL)
		err_exit();
	stack_b = NULL;
	create_index(&stack_a, numbers, size);
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	free(numbers);
	return (EXIT_SUCCESS);
}
