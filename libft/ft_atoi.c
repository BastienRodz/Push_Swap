/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:42:44 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/23 08:43:22 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	long long int	res;
	long long int	sign;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (res * sign > INT_MAX || res * sign < INT_MIN)
			ft_error();
	return ((int)(res * sign));
}
