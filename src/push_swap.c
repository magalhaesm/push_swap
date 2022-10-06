/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:02:51 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/06 13:37:36 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*numbers;

	numbers = parse_int(argc - 1, argv + 1);
	if (numbers == NULL)
		err_exit();
	free(numbers);
	return (EXIT_SUCCESS);
}
