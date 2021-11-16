/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:58:04 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/09 16:06:10 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_data	*ft_lstnew(int nbr, int i)
{
	t_data	*list;

	list = (t_data *)malloc(sizeof(t_data *));
	if (!list)
		return (0);
	list->nbr = nbr;
	list->index = i;
	list->next = NULL;
	return (list);
}
