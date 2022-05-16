# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 18:10:54 by lorfanu           #+#    #+#              #
#    Updated: 2022/04/08 14:21:32 by lorfanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = *.c

OBJS = $(SRCS:.c=.o)

all:
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re
