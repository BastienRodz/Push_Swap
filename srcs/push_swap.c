/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:20:30 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 18:57:59 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_global	g;
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (ac < 2)
		ft_error();
	ft_are_digits(av);
	ft_good_digits(av);
	ft_create_list(av, &stack_a);
	g.stack_a = &stack_a;
	g.stack_b = &stack_b;
	g.av = av;
	g.size = ft_lstsize(g.stack_a);
	builder_solver_int_tab(&g, g.stack_a);
	if	(ft_is_sorted(g.stack_a))
		return (1);
	if (ac < 3)
		return (1);
	else if (ac == 4 || ac == 3)
		ft_sort_three(g.stack_a);
	else if (ac == 5 || ac == 6)
		ft_sort_five(&g, g.stack_a, g.stack_b);
	else
		ft_sort_a(&g, 0, g.size - 1);
	return (1);
}
