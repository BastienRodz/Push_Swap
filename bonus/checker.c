/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:58:31 by barodrig          #+#    #+#             */
/*   Updated: 2021/09/22 14:52:25 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_execute_next(t_data **chk_a, t_data **chk_b, char *buf)
{
	if (!ft_strcmp(buf, "rra"))
		ft_reverse_rotate(chk_a, NULL);
	else if (!ft_strcmp(buf, "rrb"))
		ft_reverse_rotate(chk_b, NULL);
	else if (!ft_strcmp(buf, "rrr"))
		ft_two_reverse_rotates(chk_a, chk_b, 0);
	else if (ft_strcmp(buf, "sa") && ft_strcmp(buf, "sb")
		&& ft_strcmp(buf, "ss") && ft_strcmp(buf, "pa")
		&& ft_strcmp(buf, "pb") && ft_strcmp(buf, "ra")
		&& ft_strcmp(buf, "rb") && ft_strcmp(buf, "rr")
		&& ft_strcmp(buf, "rra") && ft_strcmp(buf, "rrb")
		&& ft_strcmp(buf, "rrr"))
		ft_error();
	else
		return ;
}

void	ft_execute(t_data **chk_a, t_data **chk_b, char *buf)
{
	if (!ft_strcmp(buf, "sa") && *chk_a && (*chk_a)->next)
		ft_one_swap(chk_a, NULL);
	else if (!ft_strcmp(buf, "sb") && *chk_b && (*chk_b)->next)
		ft_one_swap(chk_b, NULL);
	else if (!ft_strcmp(buf, "ss"))
		ft_two_swaps(chk_a, chk_b, 0);
	else if (!ft_strcmp(buf, "pa") && *chk_b)
		ft_push(chk_b, chk_a, NULL);
	else if (!ft_strcmp(buf, "pb") && *chk_a)
		ft_push(chk_a, chk_b, NULL);
	else if (!ft_strcmp(buf, "ra") && (*chk_a)->next)
		ft_rotate(chk_a, NULL);
	else if ((*chk_b) && !ft_strcmp(buf, "rb") && (*chk_b)->next)
		ft_rotate(chk_b, NULL);
	else if (!ft_strcmp(buf, "rr"))
		ft_two_rotates(chk_a, chk_b, 0);
	else
		ft_execute_next(chk_a, chk_b, buf);
	return ;
}

void	ft_checker(t_data *chk_a, t_data *chk_b)
{
	long	ret;
	char	*buf;
	int		i;

	i = 0;
	ret = get_next_line(0, &buf);
	while (ret > 0)
	{
		ft_execute(&chk_a, &chk_b, buf);
		free(buf);
		i++;
		ret = get_next_line(0, &buf);
	}
	if (ret == -1)
		ft_error();
	if (chk_a && ft_is_sorted(chk_a) && !chk_b)
	{
		write(1, "OK\n", 3);
		return ;
	}
	else
	{
		write(1, "KO\n", 3);
		return ;
	}
}

int	main(int ac, char **av)
{
	t_data	*chk_a;
	t_data	*chk_b;

	chk_a = 0;
	chk_b = 0;
	if (ac >= 2)
	{
		ft_are_digits(av);
		ft_good_digits(av);
		ft_create_list(av, &chk_a);
		ft_checker(chk_a, chk_b);
	}
	else
		ft_error();
	return (0);
}
