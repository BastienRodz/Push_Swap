/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:49:51 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/22 11:03:54 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack_b(t_data **stack, int flag)
{
	int		n;
	t_data	*tmp;

	n = 0;
	if (!(*stack))
		return (0);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->nbr >= flag)
			n++;
		tmp = tmp->next;
	}
	if (n)
		return (1);
	else
		return (0);
}

void	ft_sort_b(t_global *g, int min, int max, int size)
{
	int	rot_count;

	rot_count = 0;
	while (ft_check_stack_b(&g->stack_b, g->tab[g->mid_b]))
	{
		if (ft_lstsize(&g->stack_b) && size == 1 && g->stack_b->next
			&& ((*g->stack_b->next).nbr >= g->tab[g->mid_b]))
			ft_one_swap(&g->stack_b, "sb");
		if (g->stack_b && g->stack_b->nbr < g->tab[g->mid_b])
		{
			ft_rotate(&g->stack_b, "rb");
			rot_count++;
		}
		else if (g->stack_b)
		{
			ft_push(&g->stack_b, &g->stack_a, "pa");
			size--;
		}
	}
	ft_check_previous_rot(&g->stack_b, rot_count, "rrb");
	ft_quicksort_a(g, g->mid_b, max);
	ft_quicksort_b(g, min, (((min + max) / 2) - 1));
}

void	ft_quicksort_b(t_global *g, int min, int max)
{
	int	size;

	if (min > max || (ft_is_sorted(&g->stack_a) && !g->stack_b))
		return ;
	g->mid_b = (min + max) / 2;
	size = max - g->mid_b + 1;
	ft_sort_b(g, min, max, size);
	return ;
}
