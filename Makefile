# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tde-jong <tde-jong@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/15 11:00:19 by tde-jong       #+#    #+#                 #
#    Updated: 2019/03/15 12:20:11 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC = main.c search.c

LIB = -L libft -lft

all: $(NAME)

$(NAME):
	@echo "[o] $(NAME): compiling library ..."
	@make -C libft
	@echo "[+] $(NAME): compiling object files"
	@$(CC) $(FLAGS) $(SRC) -c
	@echo "[+] $(NAME): compiling binary"
	@$(CC) $(FLAGS) $(SRC:.c=.o) -o $(NAME) $(LIB)

clean:
	@echo "[o] $(NAME): cleaning library ..."
	@make -C libft clean
	@echo "[-] $(NAME): removing object files"
	@rm -f $(SRC:.c=.o)

fclean: clean
	@echo "[o] $(NAME): fcleaning library ..."
	@make -C libft fclean
	@echo "[-] $(NAME): removing binary"
	@rm -f $(NAME)

re: fclean all
