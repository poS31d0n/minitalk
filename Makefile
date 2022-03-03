# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscot <sscot@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 18:00:28 by sscot             #+#    #+#              #
#    Updated: 2022/03/03 20:31:16 by sscot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: ft_printf/libftprintf.a client server minitalk.h


server: server.c minitalk.h
	@cc -Wall -Wextra -Werror server.c ft_printf/libftprintf.a -o $@

client: client.c minitalk.h
	@cc -Wall -Wextra -Werror client.c ft_printf/libftprintf.a -o $@

ft_printf/libftprintf.a:
	@make -C./ft_printf


clean:
	@make clean -C ./ft_printf

fclean: clean
	@rm -rf server client
	@make fclean -C ./ft_printf

re: fclean all

.PHONY: all re clean fclean
