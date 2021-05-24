# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 11:31:42 by rvan-aud          #+#    #+#              #
#    Updated: 2021/05/24 14:09:37 by rvan-aud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c				\
			operations.c		\
			push_swap_utils.c	\

NAME	= libpushswap.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

${NAME}:	${OBJS} 
			@${CC} ${CFLAGS} -c ${SRCS}
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
