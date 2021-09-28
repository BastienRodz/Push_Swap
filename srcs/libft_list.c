/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:08:47 by barodrig          #+#    #+#             */
/*   Updated: 2021/09/08 11:32:09 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*ft_lstnew(int nbr, int i)
{
	t_data	*list;

	list = (t_data *)malloc(sizeof(t_data));
	if (!list)
		return (0);
	list->nbr = nbr;
	list->index = i;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (lst)
	{
		lst = lst->next;
		if (lst != NULL)
			tmp = lst;
	}
	return (tmp);
}

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

void	ft_lstadd_front(t_data *new, t_data **stack)
{
	if (!stack || !new)
		return ;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	return ;
}
