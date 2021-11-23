# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 17:26:11 by psaulnie          #+#    #+#              #
#    Updated: 2021/11/15 17:27:39 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned.c \
ft_puthexa.c ft_strlen.c ft_putpnt.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libftprintf.a

%.o:	%.c ft_printf.h
		${CC} ${CFLAGS} -c $< -o $@ -I .

${NAME}: ${OBJS}
		ar -rcs ${NAME} ${OBJS}

all: ${NAME} 

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all


.PHONY:	all clean fclean re
