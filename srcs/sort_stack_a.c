/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:17:59 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/23 08:28:04 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_previous_rot(t_data **stack, int rot_count, char *str)
{
	while (rot_count)
	{
		ft_reverse_rotate(stack, str);
		rot_count--;
	}
}

int	ft_check_stack_a(t_data **stack, int flag)
{
	int		n;
	t_data	*tmp;

	n = 0;
	if (!(*stack))
		return (0);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->nbr <= flag)
			n++;
		tmp = tmp->next;
	}
	if (n)
		return (1);
	else
		return (0);
}

void	ft_sort_a(t_global *g, int min, int max, int size)
{
	int	rot_count;

	rot_count = 0;
	while (ft_check_stack_a(&g->stack_a, g->tab[g->mid_a]))
	{
		if (ft_lstsize(&g->stack_a) && size == 1 && g->stack_a->next
			&& (*g->stack_a->next).nbr <= g->tab[g->mid_a])
			ft_one_swap(&g->stack_a, "sa");
		if (g->stack_a && g->stack_a->nbr > g->tab[g->mid_a])
		{
			ft_rotate(&g->stack_a, "ra");
			rot_count++;
		}
		else if (g->stack_a)
		{
			ft_push(&g->stack_a, &g->stack_b, "pb");
			size--;
		}
	}
	ft_check_previous_rot(&g->stack_a, rot_count, "rra");
	ft_quicksort_a(g, (((min + max) / 2) + 1), max);
	ft_quicksort_b(g, min, ((min + max) / 2));
}

void	ft_quicksort_a(t_global *g, int min, int max)
{
	int		size;

	if (min >= max || (ft_is_sorted(&g->stack_a) && !g->stack_b))
		return ;
	g->mid_a = (min + max) / 2;
	size = g->mid_a - min + 1;
	ft_sort_a (g, min, max, size);
	return ;
}
