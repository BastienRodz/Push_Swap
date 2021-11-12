# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:49:05 by barodrig          #+#    #+#              #
#    Updated: 2021/11/12 15:13:31 by barodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/sh

NAME = push_swap

CC = clang -g3 -Wall -Wextra -Werror

INC= -I./includes

BONUS= \

SRCS = 	push_swap errors instructions instructions_next\
		sort_int_tab sort utils sort_three

FIL = $(addsuffix .c, $(addprefix srcs/, $(SRCS)))

OBJ = $(FIL:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

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

bonus: $(NAME)_bonus

$(NAME)_bonus : $(OBJ_BONUS)
	@echo "Compiling libft..."
	@make bonus -s -C ./libft
	@echo "--> [OK]"
	@echo "Compiling push_swap with bonus...."
	-@$(CC) $(INC) $(OBJ_BONUS) -Llibft -lft -o $(NAME)_bonus
	@echo "--> [OK]"
	@echo "Now write : ./push_swap_bonus nbr1 nbr2 nbr... nbrx"

clean:
	@echo "CLEANING ..."
	@make -s clean -C ./libft
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "--> [OK]"

fclean: clean
	@make -s fclean -C ./libft
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re bonus
