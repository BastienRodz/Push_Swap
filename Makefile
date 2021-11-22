# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:49:05 by barodrig          #+#    #+#              #
#    Updated: 2021/11/22 12:53:08 by barodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/sh

NAME = push_swap

CC = clang -fsanitize=address -g3 -Wall -Wextra -Werror

INC= -I./includes

SRCS = 	push_swap errors instructions instructions_next\
		sort_int_tab sort_stack_a utils sort_stack_b\
		sort_small

FIL = $(addsuffix .c, $(addprefix srcs/, $(SRCS)))

OBJ = $(FIL:.c=.o)

.c.o:
	-@${CC} ${INC} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling libft..."
	@make bonus -s -C ./libft
	@echo "--> [OK]"
	@echo "Compiling push_swap...."
	-@$(CC) $(INC) $(OBJ) -Llibft -lft -o $(NAME)
	@echo "--> [OK]"
	@echo "Now write : ./push_swap nbr1 nbr2 nbr... nbrx"

clean:
	@echo "CLEANING ..."
	@make -s clean -C ./libft
	@rm -rf $(OBJ)
	@echo "--> [OK]"

fclean: clean
	@make -s fclean -C ./libft
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re
