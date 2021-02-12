# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 13:26:06 by mhumfrey          #+#    #+#              #
#    Updated: 2021/02/12 19:56:23 by mhumfrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cube3d

SRC			= $(shell find . -name "comp*.c")

OBJS		= ${SRC:.c=.o}

LIBFT		= make bonus -C libft

MINILIBX    = make -C minilibx

FLAGS		= -Wall -Wextra -Werror

FRAMEWORKS	= -framework OpenGL -framework Appkit

RM			= rm -f

all:	${NAME}

.c.o:
		gcc ${FLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} cube3d.h
		${LIBFT}
		${MINILIBX}
		gcc ${FLAGS} ${OBJS} -o ${NAME} -L. -I. libft/libft.a minilibx/libmlx.a ${FRAMEWORKS}

clean:
		${RM} ${OBJS}
		make clean -C libft
		make clean -C minilibx

fclean:	clean
		${RM} ${NAME}
		make fclean -C libft
		make clean -C minilibx

re:		fclean all

.PHONY:		re all clean fclean