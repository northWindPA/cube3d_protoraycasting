# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 13:26:06 by mhumfrey          #+#    #+#              #
#    Updated: 2021/01/24 16:50:00 by mhumfrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SRC		= $(shell find . -name "cube3d*.c")

OBJS		= ${SRC:.c=.o}

LIBFT		= make -C ./../libft/

FLAGS		= -Wall -Wextra -Werror

FRAMEWORKS	= -framework OpenGL -framework Appkit

RM			= rm -f

all:	${NAME}

.c.o:
		gcc ${FLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} cub3d.h
		${LIBFT}
		cp ./../libft/libft.a .
		gcc ${FLAGS} ${OBJS} -o ${NAME} -L. -I. libft.a libmlx.a ${FRAMEWORKS}

clean:
		${RM} ${OBJS}
		${RM} ./../libft/*.o

fclean:	clean
		${RM} ${NAME}
		${RM} libft.a

re:		fclean all

.PHONY:		re all clean fclean