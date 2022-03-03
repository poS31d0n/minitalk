# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscot <sscot@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 20:18:05 by sscot             #+#    #+#              #
#    Updated: 2022/03/03 20:18:08 by sscot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=				\
				ft_printf.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_putchar.c \
				ft_putnbr_up.c \
				ft_putnbr_low.c \
				ft_putnbr_new.c \
				ft_putnbr_point.c \
				ft_format_check.c 

HEADER		=	ft_printf.h

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -I$(HEADER)

OBJ			=	$(patsubst %.c, %.o, $(SRCS))

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(HEADER)
		ar rcs $(NAME) $(OBJ) $?

%.o 		: %.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean		:
		@rm -f $(OBJ)

fclean		:	clean
		@rm -f $(NAME)

re		:	fclean all

