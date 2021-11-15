/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:44:46 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 18:34:43 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_data **stack)
{
	int		size;
	t_data	*lst;

	lst = *stack;
	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next != NULL)
		{
			lst = lst->next;
			size++;
		}
		else
			break ;
	}
	size++;
	return (size);
}
