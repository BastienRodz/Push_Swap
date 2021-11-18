/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:17:59 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 14:18:27 by barodrig         ###   ########.fr       */
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

t_data	*ft_to_middle(t_global *g, int middle_nbr, int flag)
{
	t_data	*mid;
	int		size;

	if (flag == 1)
	{
		solve_int_tab(g, &g->stack_a, 1);
		size = ft_lstsize(&g->stack_a);
		middle_nbr = (g->tab_a[0] + g->tab_a[size - 1]) / 2;
		free(g->tab_a);
		g->tab_a = 0;
		mid = g->stack_a;
		while (mid->nbr != middle_nbr)
			mid = mid->next;
		return (mid);
	}
	else if (flag == 2)
	{
		solve_int_tab(g, &g->stack_b, 2);
		size = ft_lstsize(&g->stack_b);
		middle_nbr = (g->tab_b[0] + g->tab_b[size - 1]) / 2;
		free(g->tab_b);
		g->tab_b = 0;
		mid = g->stack_b;
		while (mid->nbr != middle_nbr)
			mid = mid->next;
		return (mid);
	}
	return (NULL);
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
	t_data	*mid;
	int		rot_count;
	int		size;

	if (min > max || (ft_is_sorted(&g->stack_a) && !g->stack_b))
		return ;
	rot_count = 0;
	size = max - min + 1;
	mid = ft_to_middle(g, ((min + max) / 2), 2);
	while (ft_check_stack_b(&g->stack_b, mid->nbr))
	{
		if (ft_lstsize(&g->stack_b) && size == 1 && ( (*g->stack_b->next).nbr >= mid->nbr))
			ft_one_swap(&g->stack_b, "sb");
		if (g->stack_b && g->stack_b->nbr <  mid->nbr)
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
		ft_sort_a(g, ((min + max) / 2), max);
		ft_sort_b(g, min, (((min + max) / 2) - 1));
	return ;
}

void	ft_sort_a(t_global *g, int min, int max)
{
	t_data	*mid;
	int		rot_count;
	int		size;

	if (min >= max || (ft_is_sorted(&g->stack_a) && !g->stack_b))
		return ;
	rot_count = 0;
	size = ((min + max) / 2) + 1;
	mid = ft_to_middle(g, ((min + max) / 2), 1);
	while (ft_check_stack_a(&g->stack_a, mid->nbr))
	{
		if (ft_lstsize(&g->stack_a) && size == 1 && (*g->stack_a->next).nbr <= mid->nbr)
			ft_one_swap(&g->stack_a, "sa");
		
		if (g->stack_a && g->stack_a->nbr > mid->nbr)
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
	printf("A\n");
	ft_print_list(&g->stack_a);
	printf("\nB\n");
	ft_print_list(&g->stack_b);
	ft_sort_a(g, (((min + max) / 2) + 1), max);
	ft_sort_b(g, min, ((min + max) / 2));
	return ;
}
