/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:20:54 by barodrig          #+#    #+#             */
/*   Updated: 2021/09/11 14:22:24 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_one_swap(t_data **list, char *str)
{
	t_data	*tmp;
	t_data	*tmp_2;

	if (!(*list) || !(*list)->next)
		return;
	tmp = *list;
	tmp_2 = (*list)->next;
	tmp->next = tmp_2->next;
	tmp_2->next = tmp;
	*list = tmp_2;
	if (str)
		printf("%s\n", str);
	return ;
}

void	ft_two_swaps(t_data **list_a, t_data **list_b, int print)
{
	if (*list_a && (*list_a)->next)
		ft_one_swap(list_a, NULL);
	if (*list_b && (*list_b)->next)
		ft_one_swap(list_b, NULL);
	if (print)
		printf("ss\n");
	return ;
}

void	ft_push(t_data **src, t_data **dst, char *str)
{
	t_data	*new;

	if (!(*src))
		return;
	new = (*src)->next;
	ft_lstadd_front(*src, dst);
	*src = new;
	if (str)
		printf("%s\n", str);
	return ;
}

void	ft_rotate(t_data **stack, char *str)
{
	t_data	*new;

	if (!(*stack) || !(*stack)->next)
		return ;
	new = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	*stack = new;
	if (str)
		printf("%s\n", str);
	return ;
}

void	ft_two_rotates(t_data **stack_a, t_data **stack_b, int print)
{
	if (*stack_a && (*stack_a)->next)
		ft_rotate(stack_a, NULL);
	if (*stack_b && (*stack_b)->next)
		ft_rotate(stack_b, NULL);
	if (print)
		printf("rr\n");
}
