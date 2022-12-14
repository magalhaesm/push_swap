/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:49:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/18 10:38:13 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(char *s1, char *s2);
void	checker(t_stack **a, t_stack **b);
void	exec_valid(char *cmd, t_stack **a, t_stack **b);

int	main(int argc, char **argv)
{
	int		size;
	int		*numbers;
	t_stack	*a;
	t_stack	*b;

	size = argc - 1;
	if (size <= 1)
		return (EXIT_SUCCESS);
	numbers = parse_int(size, argv + 1);
	a = init_stack(numbers, size);
	b = NULL;
	create_index(&a, numbers, size);
	free(numbers);
	checker(&a, &b);
	if (is_sorted(a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	destroy_stack(&a);
	destroy_stack(&b);
	return (EXIT_SUCCESS);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*cmd;

	set_output(FALSE);
	cmd = "";
	while (cmd)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (cmd)
		{
			exec_valid(cmd, a, b);
			free(cmd);
			if (error())
				close(STDIN_FILENO);
		}
	}
	if (error())
	{
		destroy_stack(a);
		destroy_stack(b);
		err_exit(255);
	}
}

void	exec_valid(char *cmd, t_stack **a, t_stack **b)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		swap_a(a);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		swap_a(b);
	else if (ft_strcmp(cmd, "ss\n") == 0)
		swap_same(a, b);
	else if (ft_strcmp(cmd, "pa\n") == 0)
		push_a(a, b);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		push_b(a, b);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		rotate_a(a);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		rotate_b(b);
	else if (ft_strcmp(cmd, "rr\n") == 0)
		rotate(a, b);
	else if (ft_strcmp(cmd, "rra\n") == 0)
		reverse_rotate_a(a);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		reverse_rotate_b(b);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		reverse_rotate(a, b);
	else
		set_error(TRUE);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
