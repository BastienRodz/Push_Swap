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
