/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:13:48 by barodrig          #+#    #+#             */
/*   Updated: 2021/09/11 14:17:36 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	buf_checker(int *i, char *buf)
{
	if (!buf[*i - 1])
		*i = 0;
	if (buf[*i - 1] == '\n')
		return (1);
	return (0);
}