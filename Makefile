# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 16:29:45 by shocquen          #+#    #+#              #
#    Updated: 2021/12/16 19:14:43 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC =		gcc -o
CLIT =		client
SERV =		server
SRCS_CLIT =	srcs/client.c \
	srcs/utils.c \

SRCS_SERV = srcs/server.c

LIB = lib/libftprintf.a

INC =		includes
	
RM =		rm -rf
OBJ_CLIT =		$(SRCS_CLIT:.c=.o)
OBJ_SERV =		$(SRCS_SERV:.c=.o)
CFLAG =	-Wall -Wextra -Werror

all :		$(CLIT) $(SERV)
	@echo "server and client made"

%.o : %.c
			$(CC) $(CFLAG) -I $(INC) -c $< -o $@

$(CLIT) :	$(OBJ_CLIT) $(INC)
			$(CC) $(CLIT) $(OBJ_CLIT) $(LIB)
$(SERV) : $(OBJ_SERV) $(INC)
			$(CC) $(SERV) $(OBJ_SERV) $(LIB)

clean :
			$(RM) $(OBJ_SERV) $(OBJ_CLIT)

fclean :	clean
			$(RM) $(CLIT) $(SERV)

re : 		fclean all

.PHONY : 	all clean fclean re