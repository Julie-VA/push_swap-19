# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 11:31:42 by rvan-aud          #+#    #+#              #
#    Updated: 2021/06/27 15:17:07 by rvan-aud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PSWAP	= push_swap.c	\

SRCS_CHECKR	= checker.c	\

SRCS_UTILS	= algos/algos_bh_get_rots.c	\
			algos/algos_bh_write_rots.c	\
			algos/algos_bh_utils.c		\
			algos/algos_big.c			\
			algos/algos_huge.c			\
			algos/algos_small.c			\
			algos/algos_utils.c			\
			algos/algos3.c				\
			algos/algos4_6.c			\
			operations/push.c			\
			operations/reverserotate.c	\
			operations/rotate.c			\
			operations/swap.c			\
			errors.c					\
			free_stacks.c				\
			modgnl_utils.c				\
			modgnl.c					\
			set_stacks.c				\
			tabinit_sort.c				\
			utils.c						\

NAME		= $(PSWAP) $(CHECKER)
PSWAP		= push_swap
CHECKER		= checker

CC			= gcc -I includes
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

OBJS_PSWAP	= $(SRCS_PSWAP:.c=.o)
OBJS_CHECKR	= $(SRCS_CHECKR:.c=.o)
OBJS_UTILS	= $(SRCS_UTILS:.c=.o)
OBJS_ALL	= $(OBJS_PSWAP) $(OBJS_CHECKR) $(OBJS_UTILS)

$(PSWAP):	$(OBJS_PSWAP) $(OBJS_UTILS)
			@$(CC) $(CFLAGS) -o $(PSWAP) $(SRCS_PSWAP) $(SRCS_UTILS)

$(CHECKER):	$(OBJS_CHECKR) $(OBJS_UTILS)
			@$(CC) $(CFLAGS) -o $(CHECKER) $(SRCS_CHECKR) $(SRCS_UTILS)

all:		$(NAME)

clean:
			$(RM) $(OBJS_ALL)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
