# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 12:47:01 by mhumfrey          #+#    #+#              #
#    Updated: 2021/01/16 19:17:27 by mhumfrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

INC = libft.h

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_calloc.c \
	  ft_strlcpy.c \
	  ft_substr.c \
	  ft_split.c \
	  get_next_line.c \
	  get_next_line_utils.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) library constructed"
	@ranlib $(NAME)
	@echo "$(NAME) index branded"

bonus: all $(OBJB)
	@ar rc $(NAME) $(OBJB)
	@echo "bonus added to $(NAME)"
	@ranlib $(NAME)
	@echo "$(NAME) index rebranded"

%.o: %.c
	@gcc $(FLAG) -I $(INC) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)
	@echo "OBJ & OBJB destroyed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) destroyed"

re: fclean all

.PHONY: all, clean, fclean, re
