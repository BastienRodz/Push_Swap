/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:18:17 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/13 12:18:58 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_data **chk_a)
{
	int		i;
	long	before;
	int		size;
	t_data	*tmp;

	tmp = *chk_a;
	i = 0;
	size = ft_lstsize(chk_a);
	before = -2147483649;
	while (i < size)
	{
		if (tmp->nbr < before)
			return (FALSE);
		before = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}

void	ft_print_list(t_data **list)
{
	t_data	*tmp;

	if (!(*list))
		return ;
	tmp = *list;
	while (tmp->next)
	{
		printf("%i      index = %i\n", tmp->nbr, tmp->index);
		tmp = tmp->next;
	}
	printf("%i      index = %i\n", tmp->nbr, tmp->index);
	return ;
}

void	ft_create_list(char **av, t_data **stack_a)
{
	int		i;
	t_data	*new;

	i = 0;
	while (av[++i])
	{
		new = ft_lstnew(ft_atoi(av[i]), i);
		ft_lstadd_back(stack_a, new);
	}
	return ;
}

void	ft_good_digits(char **av)
{
	int			i;
	int			j;
	int			n;

	i = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			ft_error();
		else
			n = ft_atoi(av[i]);
		j = 0;
		while (av[++j])
		{
			if (ft_atoi(av[j]) == n && j != i)
				ft_error();
		}
	}
}

void	ft_are_digits(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9')
				|| av[i][j] == '-')
				j++;
			else
				ft_error();
		}
		i++;
	}
	return ;
}
