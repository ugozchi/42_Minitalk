# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 12:09:57 by uzanchi           #+#    #+#              #
#    Updated: 2024/08/28 12:26:02 by uzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler targets and libraries
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
CLIENT		=	client
SERVER		=	server
LIBFT		=	libft.a

# Directories
SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
LIBFT_DIR	=	./libft/
OBJ_DIR		=	${SRCS_DIR}.o

# Colours, symbols and utils
GREEN		=	\033[1;32m
CYAN		=	\033[1;36m
YELLOW		=	\033[1;33m
RED		=	\033[1;31m
NC		=	\033[0m
BOLD		=	\033[1m
TICK		=	✓
INFO		=	ⓘ

CLIENT_SRC	=	client.c
SERVER_SRC	=	server.c
COMMON_SRC	=	common_utils.c

CLIENT_SRCS	=	$(addprefix ${SRCS_DIR}, ${CLIENT_SRC})
SERVER_SRCS	=	$(addprefix ${SRCS_DIR}, ${SERVER_SRC})
COMMON_SRCS	=	$(addprefix ${SRCS_DIR}, ${COMMON_SRC})
SRC_NR		=	$(shell expr $(words ${CLIENT_SRCS}) + $(words ${SERVER_SRCS}) + $(words ${COMMON_SRCS}))

CLIENT_OBJS	=	$(addprefix ${OBJ_DIR}/, $(notdir $(CLIENT_SRCS:.c=.o)))
SERVER_OBJS	=	$(addprefix ${OBJ_DIR}/, $(notdir $(SERVER_SRCS:.c=.o)))
COMMON_OBJS	=	$(addprefix ${OBJ_DIR}/, $(notdir $(COMMON_SRCS:.c=.o)))

all:			project_logo ${OBJ_DIR}
				@make -s ${LIBFT}
				@make -s ${SERVER}
				@make -s ${CLIENT}

${LIBFT}:
				@echo "${CYAN}\nCOMPILING $$(echo ${LIBFT} | tr '[:lower:]' '[:upper:]')${NC}"
				make -C ${LIBFT_DIR}
				@echo "${YELLOW}Moving ${LIBFT} at the root of the repository${NC}"
				@mv ${LIBFT_DIR}/${LIBFT} .

${SERVER}:		entry_message ${SERVER_OBJS} ${COMMON_OBJS}
				@${CC} ${CFLAGS} ${SERVER_SRCS} ${COMMON_SRCS} -I${HEAD_DIR} ${LIBFT} -o ${SERVER}

${CLIENT}:		${CLIENT_OBJS} ${COMMON_OBJS}
				@${CC} ${CFLAGS} ${CLIENT_SRCS} ${COMMON_SRCS} -I${HEAD_DIR} ${LIBFT} -o ${CLIENT}
				@echo "${YELLOW}\nCompilation complete, ${CLIENT} and ${SERVER} executable at the root of the directory${NC}\n"

${OBJ_DIR}:
				@if [ ! -d "${OBJ_DIR}" ]; \
				then mkdir -p "${OBJ_DIR}"; \
				fi

$(OBJ_DIR)/%.o:	$(SRCS_DIR)%.c
				@echo -n "Compiling $(notdir $<)"; \
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@; \
				echo "${GREEN} ${TICK}${NC}"; 

clean:
				@make -sC ${LIBFT_DIR} clean >/dev/null 2>&1
				@if [ ! -d "${OBJ_DIR}" ]; \
				then \
					echo "${YELLOW}${INFO} Repo .o already clean${NC}"; \
				else \
					echo "${RED}Removing all .o files${NC}"; \
					rm -r ${OBJ_DIR}; \
				fi

fclean:			clean
				@make -sC ${LIBFT_DIR} fclean >/dev/null 2>&1
				@echo "${RED}Removing excutables and ${LIBFT} files from root ${NC}"
				@rm -f ${SERVER} ${CLIENT} ${LIBFT}

re:				fclean all

project_logo:
	@echo "\033[38;5;231m    ▁▁▁▁▁ ▁▁▁▁▁▁▁▁              ▁▁▁▁▁  .▁▁       .▁▁▁▁▁▁▁▁▁▁▁▁▁      .▁▁   ▁▁        \033[0m"
	@echo "\033[38;5;195m   ╱  │  │╲▁▁▁▁▁  ╲            ╱     ╲ │▁▁│ ▁▁▁▁ │▁▁╲▁▁    ▁▁▁╱▁▁▁▁  │  │ │  │ ▁▁    \033[0m"
	@echo "\033[38;5;159m  ╱   │  │▁╱  ▁▁▁▁╱   ▁▁▁▁▁▁  ╱  ╲ ╱  ╲│  │╱    ╲│  │ │    │  ╲▁▁  ╲ │  │ │  │╱ ╱    \033[0m"
	@echo "\033[38;5;123m ╱    ^   ╱       ╲  ╱▁▁▁▁▁╱ ╱    Y    ╲  │   │  ╲  │ │    │   ╱ ▁▁ ╲│  │▁│    <     \033[0m"
	@echo "\033[38;5;123m ╲▁▁▁▁   │╲▁▁▁▁▁▁▁ ╲         ╲▁▁▁▁│▁▁  ╱▁▁│▁▁▁│  ╱▁▁│ │▁▁▁▁│  (▁▁▁▁  ╱▁▁▁▁╱▁▁│▁ ╲    \033[0m"
	@echo "\033[38;5;123m      │▁▁│        ╲╱                 ╲╱        ╲╱                  ╲╱          ╲╱    \033[0m"
	@echo "\033[38;5;123m							a 42 Project by Ugo ZANCHI	  \033[0m"

entry_message:
				@echo "${CYAN}\nCOMPILING $$(echo ${SERVER} | tr '[:lower:]' '[:upper:]') and $$(echo ${CLIENT} | tr '[:lower:]' '[:upper:]')\n${NC}${BOLD}Compiling necessary .o files out of ${SRC_NR} .c files in total${NC}"

.PHONY:			all clean fclean delete re project_logo entry_message
