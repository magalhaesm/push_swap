/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:45:10 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/09 12:47:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# include "libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		*parse_int(int size, char **input);
long	ft_atol(const char *nptr);
void	err_exit(void);

t_stack	*init_stack(int *input, int size);
void	create_index(t_stack **stack, int *input, int size);
void	destroy_stack(t_stack **top);
void	push(t_stack **stack, t_stack *item);
t_stack	*pop(t_stack **stack);
void	push_bottom(t_stack **stack, t_stack *item);
t_stack	*pop_bottom(t_stack **stack);
int		stack_size(t_stack *stack);

#endif
