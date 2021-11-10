/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:20:30 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/09 16:50:53 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*stack_a;
	t_data	*stack_b;
	t_global g;
	int		size;

	stack_a = 0;
	stack_b = 0;
	if (ac < 2)
		ft_error();
	ft_are_digits(av);
	ft_good_digits(av);
	ft_create_list(av, &stack_a);
	g.stack_a = &stack_a;
	g.stack_b = &stack_b;
	size = ft_lstsize(&stack_a);
	builder_solver_int_tab(&g, g.stack_a);
	//ft_sort_a(&stack_a, &stack_b, 0, size - 1);
	return (1);
}
