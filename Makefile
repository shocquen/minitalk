# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 16:29:45 by shocquen          #+#    #+#              #
#    Updated: 2022/01/03 11:05:48 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED=\033[0;31m
GRN=\033[1;32m
NC=\033[0m # No Color

CC =		gcc -o
CLIT =		client
SERV =		server
SRCS_CLIT =	srcs/client.c \
	srcs/utils.c \

SRCS_SERV = srcs/server.c

LIB_ARM =	lib/arm/libft.a
LIB_86 = lib/86/libft.a

INC =		includes
	
RM =		rm -rf
OBJ_CLIT =		$(SRCS_CLIT:.c=.o)
OBJ_SERV =		$(SRCS_SERV:.c=.o)
CFLAG =	-Wall -Wextra -Werror

# Compile the right libft.a
proc =	$(shell uname -m )
ifeq ($(proc),arm64)
	LIB =	$(LIB_ARM)
else
	LIB = $(LIB_86)
endif

all :	$(CLIT) $(SERV)

%.o : %.c
			$(CC) $(CFLAG) -I $(INC) -c $< -o $@

$(CLIT) :	$(OBJ_CLIT)
	$(CC) $(CLIT) $(OBJ_CLIT) $(LIB)
	@echo "${GRN}Client made.${NC}"

$(SERV) : $(OBJ_SERV)
	$(CC) $(SERV) $(OBJ_SERV) $(LIB)
	@echo "${GRN}Server made.${NC}"

clean :
			$(RM) $(OBJ_SERV) $(OBJ_CLIT)

fclean :	clean
			$(RM) $(CLIT) $(SERV)

re : 		fclean all

bonus : all
	@echo "${GRN}Bonuses dones.${NC}"

.PHONY : 	all clean fclean re
