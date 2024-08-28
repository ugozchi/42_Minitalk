# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 11:23:36 by uzanchi           #+#    #+#              #
#    Updated: 2024/07/03 11:27:01 by uzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
#BONUS_NAMEC = client_bonus
#BONUS_NAMES = server_bonus
LIBFT = libft.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
#BONUSC_FILES = client_bonus.c 
#BONUSS_FILES = server_bonus.c
SRC_DIR = sources/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
#BONUSC = $(addprefix $(SRC_DIR), $(BONUSC_FILES))
#BONUSS = $(addprefix $(SRC_DIR), $(BONUSS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
#OBJBC = ${BONUSC:.c=.o}
#OBJBS = ${BONUSS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C libft
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) libft/$(LIBFT) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C libft
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) libft/$(LIBFT) -o $(NAMES)

#bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

#$(BONUS_NAMEC) : $(OBJBC)
#				@make -C printf
#				$(CC) $(CFLAGS) $(OBJBC)  $(INCLUDE)  printf/$(PRINTF) -o $(BONUS_NAMEC)

#$(BONUS_NAMES) : $(OBJBS)
#				@make -C printf
#				$(CC) $(CFLAGS) $(OBJBS)  $(INCLUDE)  printf/$(PRINTF) -o $(BONUS_NAMES)

clean :
		@make clean -C libft
		${RM} ${OBJC}
		${RM} ${OBJS}
#		${RM} ${OBJBC}
#		${RM} ${OBJBS}

fclean : clean
		@make fclean -C libft
		${RM} $(NAMEC)
		${RM} $(NAMES)
#		${RM} $(BONUS_NAMEC)
#		${RM} $(BONUS_NAMES)
		${RM} $(LIBFT)

re : fclean all

.PHONY:		all bonus clean fclean re
