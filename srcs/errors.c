/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:03:29 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/23 08:36:06 by barodrig         ###   ########.fr       */
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
	return ;
}

void	ft_free_stacks(t_global *g)
{
	t_data	*tmp;

	while (g->stack_a->next)
	{
		tmp = g->stack_a->next;
		if (g->stack_a)
			free(g->stack_a);
		g->stack_a = tmp;
	}
	if (tmp)
		free(tmp);
}

void	ft_error_free(t_global *g)
{
	ft_free_tabs(g);
	ft_free_stacks(g);
	exit(0);
}
