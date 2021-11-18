/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:03:29 by barodrig          #+#    #+#             */
/*   Updated: 2021/09/11 16:24:28 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_tabs(t_global *g)
{
	if (g->tab)
		free(g->tab);
	if (g->tab_a)
		free(g->tab_a);
	if (g->tab_b)
		free(g->tab_b);
}

void	ft_free_stacks(t_global *g)
{
	t_data *tmp;
	
	while (g->stack_a->next)
	{
		tmp = g->stack_a->next;
		free(g->stack_a);
		g->stack_a = tmp;
	}
	if (tmp)
		free(tmp);
	if (g->stack_a)
		free(g->stack_a);
}

void	ft_error_free(t_global *g)
{
	ft_free_tabs(g);
	ft_free_stacks(g);
	exit(0);
}
