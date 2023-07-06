# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:25:34 by evdos-sa          #+#    #+#              #
#    Updated: 2023/07/06 18:12:13 by evdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_SB = server_bonus
NAME_CB = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
RM = rm -rf

GREEN_COLOR = \033[38;5;46m
BLUE_COLOR = \033[38;5;33m
PINK_COLOR = \033[38;5;200m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(LIBFT)
	@echo "$(GREEN_COLOR)Compiling Minitalk...$(RESET)"
	@$(CC) $(CFLAGS) src/server.c $(LIBFT) -o $(NAME_S)

$(NAME_C): $(LIBFT)
	@$(CC) $(CFLAGS) src/client.c $(LIBFT) -o $(NAME_C)
	@echo "$(YELLOW)Minitalk compiled!$(RESET)"

$(LIBFT):
	@echo "$(PINK_COLOR)Compiling libft...$(RESET)"
	@$(MAKE) -C ./libft bonus
	@echo "$(YELLOW)Libft compiled!$(RESET)"

clean:
	@echo "$(PINK_COLOR)Cleaning libft objects...$(RESET)"
	@$(MAKE) -C ./libft clean
	@echo "$(YELLOW)Libft objects cleaned!$(RESET)"
	
fclean: clean
	@echo "$(PINK_COLOR)Cleaning minitalk and libft...$(RESET)"
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME_S) $(NAME_C) $(NAME_SB) $(NAME_CB)
	@echo "$(YELLOW)Minitalk and libft cleaned!$(RESET)"

bonus: fclean $(NAME_SB) $(NAME_CB)
	
$(NAME_SB): $(LIBFT)
	@echo "$(BLUE_COLOR)Compiling Minitalk Bonus...$(RESET)"
	@$(CC) $(CFLAGS) src/server_bonus.c $(LIBFT) -o $(NAME_SB)

$(NAME_CB): $(LIBFT)
	@$(CC) $(CFLAGS) src/client_bonus.c $(LIBFT) -o $(NAME_CB)
	@echo "$(YELLOW)Minitalk Bonus compiled!$(RESET)"

re: fclean all

re_bonus: fclean bonus

.PHONY: clean fclean all re

# MAKE DO MINITALK

# all:
# 	@cd ft_printf && make all
# 	@gcc -Wall -Wextra -Werror src/server.c ft_printf/libftprintf.a -o server
# 	@gcc -Wall -Wextra -Werror src/client.c ft_printf/libftprintf.a -o client

# clean:
# 	@cd ft_printf && make clean
# 	@rm -f server
# 	@rm -f client

# fclean: clean
# 	@cd ft_printf && make fclean

# re: fclean all

# bonus: fclean
# 	@cd ft_printf && make all
# 	@gcc -Wall -Wextra -Werror "bonus src/server_bonus.c" ft_printf/libftprintf.a -o server
# 	@gcc -Wall -Wextra -Werror "bonus src/client_bonus.c" ft_printf/libftprintf.a -o client
