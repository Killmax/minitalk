##
## Makefile for minitalk in /home/brugue_m/rendu/PSU_2014_minitalk
## 
## Made by bruguet Maxime
## Login   <brugue_m@epitech.net>
## 
## Started on  Wed Feb 25 16:10:03 2015 bruguet Maxime
## Last update Mon Mar  9 15:11:17 2015 bruguet Maxime
##

CLIENT		= ./client/client

SERVER		= ./server/server

SRC_CLIENT	= ./client/client.c \
		./client/my_getnbr.c \
		./client/my_put.c \
		./client/my_str_isnum.c \
		./client/convert.c

SRC_SERVER	= ./server/server.c \
		./server/my_put.c \
		./server/calc.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

CC		= gcc

CFLAGS		+= -Wall -Wextra -I./include/

RM		= rm -f

all:		$(CLIENT) $(SERVER)

$(SERVER):	$(OBJ_SERVER)
		$(CC) -o $(SERVER) $(OBJ_SERVER)

$(CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(CLIENT) $(OBJ_CLIENT)

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:		clean
		$(RM) $(SERVER) $(CLIENT)

re:		fclean all
