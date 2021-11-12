/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:20:30 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 15:15:47 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(t_global *g, char **av)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = 0;
	stack_b = 0;
	ft_create_list(av, &stack_a);
	g->stack_a = &stack_a;
	g->stack_b = &stack_b;
	return ;
}

int	main(int ac, char **av)
{
	t_global	g;
	int			size;

	if (ac < 2)
		ft_error();
	ft_are_digits(av);
	ft_good_digits(av);
	ft_init(&g, av);
	size = ft_lstsize(g.stack_a);
	builder_solver_int_tab(&g, g.stack_a);
	if (ac <= 4)
		ft_sort_three(g.stack_a);
	/*else if (ac <= 6 && ac > 4)
		ft_sort_five();
	else
		ft_quick_sort();
	*/
	//ft_sort_a(&stack_a, &stack_b, 0, size - 1);
	return (1);
}
