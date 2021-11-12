/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:51:01 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 14:15:22 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_data **stack, char *str)
{
	t_data	*new;
	t_data	*end;

	end = *stack;
	new = 0;
	if (!(*stack) || !(*stack)->next)
		return ;
	while (end->next)
	{
		if (end->next)
		{
			if (!(end->next->next))
			{
				new = end->next;
				end->next = NULL;
			}
		}
		if (end->next)
			end = end->next;
	}
	ft_lstadd_front(new, stack);
	if (str)
		printf("%s\n", str);
	return ;
}

void	ft_two_reverse_rotates(t_data **stack_a, t_data **stack_b, int print)
{
	if ((*stack_a) && (*stack_a)->next)
		ft_reverse_rotate(stack_a, NULL);
	if ((*stack_b) && (*stack_b)->next)
		ft_reverse_rotate(stack_b, NULL);
	if (print)
		printf("rrr\n");
}
