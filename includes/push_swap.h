/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:20:33 by barodrig          #+#    #+#             */
/*   Updated: 2021/11/12 18:47:00 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 1024

/**
**	OTHER UTILS
**/
void	ft_error(void);
void	ft_print_list(t_data **list_a);
void	ft_create_list(char **av, t_data **stack_a);
void	ft_good_digits(char **av);
void	ft_are_digits(char **av);
int		ft_is_sorted(t_data **chk_a);
int	    ft_is_reverse_sorted(t_data **chk_a);

/**
** LIST INSTRUCTIONS
**/
void	ft_one_swap(t_data **list, char *str);
void	ft_two_swaps(t_data **list_a, t_data **list_b, int print);
void	ft_push(t_data **src, t_data **dst, char *str);
void	ft_rotate(t_data **stack, char *str);
void	ft_two_rotates(t_data **stack_a, t_data **stack_b, int print);
void	ft_reverse_rotate(t_data **stack, char *str);
void	ft_two_reverse_rotates(t_data **stack_a, t_data **stack_b, int print);

/**
**	SOLVER
**/
void	ft_sort_a(t_global *g, int min, int max);
void	quicksort_int_tab(int *tab, int min, int max);
void	builder_solver_int_tab(t_global *g, t_data **stack);
void	ft_sort_three(t_data **stack);
void	ft_sort_five(t_global *g, t_data **stack_a, t_data **stack_b);

/**
** BONUS CHECKER
**/
int		get_next_line(int fd, char **line);
int		buf_checker(int *i, char *buf);

#endif
