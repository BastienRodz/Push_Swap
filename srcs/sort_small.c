/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:40:11 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 15:16:17 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_data **stack)
{
	if ((*stack)->nbr > (*stack)->next->nbr
		&& !(*stack)->next->next)
		ft_one_swap(stack, "sa");
	else if ((*stack)->nbr > (*stack)->next->nbr
		&& (*stack)->nbr < (*stack)->next->next->nbr)
		ft_one_swap(stack, "sa");
	else if ((*stack)->nbr > (*stack)->next->nbr
		&& (*stack)->next->nbr > (*stack)->next->next->nbr)
	{
		ft_one_swap(stack, "sa");
		ft_reverse_rotate(stack, "rra");
	}
	else if ((*stack)->nbr > (*stack)->next->next->nbr
		&& (*stack)->next->nbr < (*stack)->next->next->nbr)
		ft_rotate(stack, "ra");
	else if ((*stack)->nbr < (*stack)->next->next->nbr
		&& (*stack)->next->nbr > (*stack)->next->next->nbr)
	{
		ft_one_swap(stack, "sa");
		ft_rotate(stack, "ra");
	}
	else if ((*stack)->nbr < (*stack)->next->nbr
		&& (*stack)->nbr > (*stack)->next->next->nbr)
		ft_reverse_rotate(stack, "rra");
	return ;
}

int	ft_is_reverse_sorted(t_data **chk_a)
{
	int		i;
	long	before;
	int		size;
	t_data	*tmp;

	tmp = *chk_a;
	i = 0;
	size = ft_lstsize(chk_a);
	before = 2147483649;
	while (i < size)
	{
		if (tmp->nbr > before)
			return (FALSE);
		before = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}

int	ft_is_the_weird_case(t_global *g, t_data **stack_a)
{
	if (g->tab[2] == (*stack_a)->nbr
		&& g->tab[4] == (*stack_a)->next->nbr
		&& g->tab[3] == (*stack_a)->next->next->nbr
		&& g->tab[1] == (*stack_a)->next->next->next->nbr
		&& g->tab[0] == (*stack_a)->next->next->next->next->nbr)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_check_weird_case(t_global *g, t_data **stack_a, t_data **stack_b)
{
	if (g->size == 4)
		return ;
	if (ft_is_reverse_sorted(stack_a) || ft_is_the_weird_case(g, stack_a))
	{
		ft_reverse_rotate(stack_a, "rra");
		ft_push(stack_a, stack_b, "pb");
		ft_reverse_rotate(stack_a, "rra");
		ft_push(stack_a, stack_b, "pb");
		ft_sort_three(stack_a);
		ft_push(stack_b, stack_a, "pa");
		ft_push(stack_b, stack_a, "pa");
	}
	return ;
}

void	ft_sort_five(t_global *g, t_data **stack_a, t_data **stack_b)
{
	int	max_push;

	max_push = 1;
	if (g->size == 5)
		max_push = 2;
	g->min = g->tab[0];
	ft_check_weird_case(g, stack_a, stack_b);
	while (max_push)
	{
		while ((*stack_a)->nbr != g->min)
			ft_rotate(stack_a, "ra");
		if (ft_is_sorted(stack_a) && !(*stack_b))
			return ;
		if ((*stack_a)->nbr == g->min)
		{
			ft_push(stack_a, stack_b, "pb");
			max_push--;
			g->min = g->tab[1];
		}
	}
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, "pa");
	if (g->size == 5)
		ft_push(stack_b, stack_a, "pa");
	return ;
}
