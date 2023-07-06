# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 11:32:44 by evdos-sa          #+#    #+#              #
#    Updated: 2023/07/06 18:22:02 by evdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_striteri.c\
	ft_atol.c ft_isldigit.c ft_printf.c ft_printfchars.c ft_printfhexa.c\
	ft_printfnum.c ft_printfpointer.c 

B_SRCS = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $@ $^

bonus: $(OBJS) $(B_OBJS)
	@ar -crs $(NAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

so:
	@$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(B_SRCS)
	@cc -nostartfiles -shared -o libft.so $(OBJS) $(B_OBJS)

.PHONY: all bonus clean fclean re
