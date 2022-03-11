# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 14:28:23 by hjanis            #+#    #+#              #
#    Updated: 2022/03/11 14:47:51 by hjanis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = minitalk.h
CLIENT = client.c
SERVER = server.c
CLIENT_BONUS = client_bonus.c
SERVER_BONUS = server_bonus.c
OBJ_CLIENT = $(patsubst %.c,%.o,$(CLIENT))
OBJ_SERVER = $(patsubst %.c,%.o,$(SERVER))
OBJ_CLIENT_BONUS = $(patsubst %.c,%.o,$(CLIENT_BONUS))
OBJ_SERVER_BONUS = $(patsubst %.c,%.o,$(SERVER_BONUS))

all: server client

server: $(OBJ_SERVER) $(HEADER)
	cc -Wall -Wextra -Werror server.c -o server

client: $(OBJ_CLIENT) $(HEADER)
	cc -Wall -Wextra -Werror client.c -o client

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) server client
	rm -f $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) server_bonus client_bonus

fclean: clean

bonus: server_bonus client_bonus
server_bonus: $(OBJ_SERVER_BONUS) $(HEADER)
	cc -Wall -Wextra -Werror server.c -o server_bonus

client_bonus: $(OBJ_CLIENT_BONUS) $(HEADER)
	cc -Wall -Wextra -Werror client.c -o client_bonus

re: fclean all