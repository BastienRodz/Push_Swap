/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:17:59 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/09 16:20:06 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	ft_check_previous_rot(t_data **stack, int rot_count, char *str)
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

t_data	*ft_to_middle(t_data **stack, int middle_index)
{
	int		i;
	t_data	*middle;

	i = 0;
	if ((*stack))
		middle = *stack;
	while (i <= middle_index)
	{
		if (middle->next)
			middle = middle->next;
		i++;
	}
	return (middle);
}
int	ft_check_stack_b(t_data **stack, int flag)
{
	int		n;
	t_data *tmp;

	n = 0;
	if (!(*stack))
		return (1);
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
		return (1);
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

	if (min > max || (ft_is_sorted(g->stack_a) && !(g->(*stack_b))))
		return ;
	rot_count = 0;
	size = max - min + 1;
	mid = ft_to_middle(stack_b, ((min + max) / 2));
	while (ft_check_stack_b(g->stack_b, mid->nbr))
	{
		if (ft_lstsize(g->stack_b) && size == 1 && (g->(*stack_b)->nbr >= mid->nbr))
			ft_one_swap(g->stack_b, "sb");
		if (g->(*stack_b)->nbr <  mid->nbr)
		{
			ft_rotate(g->stack_b, "rb");
			rot_count++;
		}
		else
		{
			ft_push(g->stack_b, g->stack_a, "pa");
			size--;
		}
	}
		ft_check_previous_rot(g->stack_b, rot_count, "rrb");
		ft_new_index(g->stack_a, g->stack_b);
		ft_sort_a(g->stack_a, g->stack_b, ((min + max) / 2), max);
		ft_sort_b(g->stack_a, g->stack_b, min, (((min + max) / 2) - 1));
	return ;
}

void	ft_sort_a(t_global *g, int min, int max)
{
	t_data	*mid;
	int		rot_count;
	int		size;

	if (min >= max || (ft_is_sorted(g->stack_a) && !(g->(*stack_b))))
		return ;
	rot_count = 0;
	mid = ft_to_middle(g->stack_a, ((min + max) / 2));
	size = ((min + max) / 2) + 1;
	mid = ft_to_middle(g->stack_a, ((min + max) / 2));
	while (ft_check_stack_a(g->stack_a, mid->nbr))
	{
		if (ft_lstsize(g->stack_a) && size == 1 && g->(*stack_a)->next->nbr <= mid->nbr)
			ft_one_swap(g->stack_a, "sa");
		if (g->(*stack_a)->nbr > mid->nbr)
		{
			ft_rotate(g->stack_a, "ra");
			rot_count++;
		}
		else
		{
			ft_push(g->stack_a, g->stack_b, "pb");
			size--;
		}
	}
	ft_check_previous_rot(g->stack_a, rot_count, "rra");
	ft_new_index(g->stack_a, g->stack_b);
	ft_sort_a(g->stack_a, g->stack_b, (((min + max) / 2) + 1), max);
	ft_sort_b(g->stack_a, g->stack_b, min, ((min + max) / 2));
	return ;
}*/
