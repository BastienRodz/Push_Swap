/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:17:59 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/18 18:43:19 by barodrig         ###   ########.fr       */
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

void	ft_new_index(t_data **stack_a, t_data **stack_b)
{
	t_data	*tmp;
	t_data	*tmp2;
	int		i;

	if ((*stack_a))
		tmp = (*stack_a);
	else
		tmp = NULL;
	if ((*stack_b))
		tmp2 = *stack_b;
	else
		tmp2 = NULL;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	i = 0;
	while (tmp2)
	{
		tmp2->index = i++;
		tmp2 = tmp2->next;
	}
}

int	ft_check_stack_b(t_data **stack, int flag)
{
	int		n;
	t_data *tmp;

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

int	ft_check_stack_a(t_data **stack, int flag)
{
	int		n;
	t_data *tmp;

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

void	ft_sort_b(t_global *g, int min, int max)
{
	int		mid;
	int		rot_count;
	int		size;


	if (min > max || (ft_is_sorted(&g->stack_a) && !g->stack_b))
		return ;
	rot_count = 0;
	mid = (min + max) / 2;
	size = max - mid + 1;
	while (ft_check_stack_b(&g->stack_b, g->tab[mid]))
	{
		if (ft_lstsize(&g->stack_b) && size == 1 && g->stack_b->next
			&&((*g->stack_b->next).nbr >= g->tab[mid]))
			ft_one_swap(&g->stack_b, "sb");
		if (g->stack_b && g->stack_b->nbr <  g->tab[mid])
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
		ft_new_index(&g->stack_a, &g->stack_b);
		ft_sort_a(g, mid, max);
		ft_sort_b(g, min, (((min + max) / 2) - 1));
	return ;
}

void	ft_sort_a(t_global *g, int min, int max)
{
	int		mid;
	int		rot_count;
	int		size;

	if (min >= max|| (ft_is_sorted(&g->stack_a) && !g->stack_b))
		return ;
	rot_count = 0;
	mid = (min + max) / 2;
	size = mid - min + 1;
	while (ft_check_stack_a(&g->stack_a, g->tab[mid]))
	{
		if (ft_lstsize(&g->stack_a) && size == 1 && g->stack_a->next
			&& (*g->stack_a->next).nbr <= g->tab[mid])
			ft_one_swap(&g->stack_a, "sa");
		if (g->stack_a && g->stack_a->nbr > g->tab[mid])
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
	ft_new_index(&g->stack_a, &g->stack_b);
	ft_sort_a(g, (((min + max) / 2) + 1), max);
	ft_sort_b(g, min, ((min + max) / 2));
	return ;
}
