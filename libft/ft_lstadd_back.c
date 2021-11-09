/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:33:20 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/09 16:07:22 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_data **stack, t_data *new)
{
	t_data	*last;

	if (stack == NULL)
		return ;
	last = *stack;
	if (*stack == NULL)
		*stack = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
		new->next = NULL;
	}
}
