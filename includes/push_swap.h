/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:20:33 by barodrig          #+#    #+#             */
/*   Updated: 2021/09/23 16:18:36 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 1024

typedef struct s_global
{
	int				*tab;
	struct	s_data	**stack_a;
	struct	s_data	**stack_b;
	struct	s_data	*mid;
}					t_global;

typedef struct s_data
{
	int				nbr;
	int				index;
	struct	s_data	*next;
}					t_data;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/**
** LIBFT UTILS
**/
t_data	*ft_lstnew(int nbr, int i);
void	ft_lstadd_front(t_data *new, t_data **stack);
int		ft_lstsize(t_data **stack);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_data **stack, t_data *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
long	ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

/**
**	OTHER UTILS
**/
void	ft_error(void);
void	ft_print_list(t_data **list_a);
void	ft_create_list(char **av, t_data **stack_a);
void	ft_good_digits(char **av);
void	ft_are_digits(char **av);
int		ft_is_sorted(t_data **chk_a);



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
void	ft_sort_a(t_data **stack_a, t_data **stack_b, int min, int max);
void	quicksort_int_tab(int *tab, int min, int max);
void	builder_solver_int_tab(t_global *g, t_data **stack);

/**
** BONUS CHECKER
**/
int		get_next_line(int fd, char **line);
int		buf_checker(int *i, char *buf);

#endif
