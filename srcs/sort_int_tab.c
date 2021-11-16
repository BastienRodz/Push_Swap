/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:39:17 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 18:53:10 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *tmp, int *tab, int value1, int value2)
{
	*tmp = tab[value1];
	tab[value1] = tab[value2];
	tab[value2] = *tmp;
	return ;
}

void	init_values(int *value1, int *value2, int min, int max)
{
	*value1 = min;
	*value2 = max;
	return ;
}

void	quicksort_int_tab(int *tab, int min, int max)
{
	int	pivot;
	int	value1;
	int	value2;
	int	tmp;

	if (min < max)
	{
		init_values(&value1, &value2, min, max);
		pivot = min;
		while (value1 < value2)
		{
			while (tab[value1] <= tab[pivot] && value1 <= max)
				value1++;
			while (tab[value2] > tab[pivot] && value2 >= min)
				value2--;
			if (value1 < value2)
			{
				ft_swap(&tmp, tab, value1, value2);
			}
		}
		tmp = tab[value2];
		tab[value2] = tab[pivot];
		tab[pivot] = tmp;
		quicksort_int_tab(tab, min, value2 - 1);
		quicksort_int_tab(tab, value2 + 1, max);
	}
	return ;
}

void	builder_solver_int_tab(t_global *g, t_data **stack)
{
	t_data	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	g->tab = (int *)malloc(sizeof(int) * g->size);
	while (tmp)
	{
		if (tmp->next != NULL)
		{
			g->tab[i++] = tmp->nbr;
			tmp = tmp->next;
		}
		else
			break ;
	}
	g->tab[i] = tmp->nbr;
	quicksort_int_tab(g->tab, 0, g->size - 1);
	return ;
}
