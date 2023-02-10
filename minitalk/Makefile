# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 08:41:40 by maricard          #+#    #+#              #
#    Updated: 2023/02/10 11:36:56 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a
RM = rm -rf

SERVER = server
CLIENT = client
SERVER-BONUS = server-bonus
CLIENT-BONUS = client-bonus

SRC-SERVER = ./mandatory/server.c
SRC-CLIENT = ./mandatory/client.c
SRC-SERVER-BONUS = ./bonus/server_bonus.c
SRC-CLIENT-BONUS = ./bonus/client_bonus.c

OBJ-SERVER = $(SRC-SERVER:.c=.o)
OBJ-CLIENT = $(SRC-CLIENT:.c=.o)
OBJ-SERVER-BONUS = $(SRC-SERVER-BONUS:.c=.o)
OBJ-CLIENT-BONUS = $(SRC-CLIENT-BONUS:.c=.o)

NAME = $(SERVER) $(CLIENT)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER): $(OBJ-SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-SERVER) $(LIBFT) -o server
$(CLIENT): $(OBJ-CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-CLIENT) $(LIBFT) -o client
$(SERVER-BONUS): $(OBJ-SERVER-BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-SERVER-BONUS) $(LIBFT) -o server-bonus
$(CLIENT-BONUS): $(OBJ-CLIENT-BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-CLIENT-BONUS) $(LIBFT) -o client-bonus

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ-SERVER) $(OBJ-CLIENT)
	$(RM) $(OBJ-SERVER-BONUS) $(OBJ-CLIENT-BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER-BONUS) $(CLIENT-BONUS)

re: fclean all

bonus: $(SERVER-BONUS) $(CLIENT-BONUS)
