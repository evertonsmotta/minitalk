# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 18:14:58 by evdos-sa          #+#    #+#              #
#    Updated: 2023/01/21 12:35:27 by evdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c\
			ft_printfchars.c \
			ft_printfpointer.c \
			ft_printfhexa.c \
			ft_printfnum.c\
			
OBJS = $(SRCS:.c=.o)

HEADER	=	ft_printf.h
CC = cc
CFLAGS	= 	-Wall -Wextra -Werror
NAME	=	libftprintf.a

all:	$(NAME)

$(NAME): $(OBJS) $(HEADER)
		ar rcs $@ $^

.c.o:	$(SRCS)
		cc $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		clean all

.PHONY: all clean fclean re
