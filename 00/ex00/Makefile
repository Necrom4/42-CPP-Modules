# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 10:39:07 by dferreir          #+#    #+#              #
#    Updated: 2023/05/26 11:05:29 by dferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN		= \033[0;32m
RED 		= \033[0;31m
BOLD		= \033[1m
NORMAL		= \033[0m
UP 			= \033[A
CUT 		= \033[K

#OUTPUT
NAME		= megaphone

#FILES
SRCS		= megaphone.cpp

OBJS_DIR	= ./objs/
OBJS_FILES	:= ${SRCS:.cpp=.o}
OBJS		:= ${addprefix ${OBJS_DIR}, ${OBJS_FILES}}

#COMMANDS
CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
AR			= ar rcs
MKDIR		= mkdir -p
RM			= rm -rf

all: ${NAME}

#Compile normal executable
${NAME}:
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) created and compiled object files"
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) is ready"

#Create objects directory
${OBJS_DIR}:
	@${MKDIR} ${OBJS_DIR}

#Compile normals objects
${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@echo "$(RED)[$(BOLD)Compiling$(NORMAL)$(RED)]$(NORMAL) $<$(UP)$(CUT)"
	@${CC} ${CFLAGS} ${INCS} -o $@ -c $<

#Clean obj files
clean:
	@${RM} ${OBJS_DIR}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) object files deleted"

#Clean objs files and name
fclean:	clean
	@${RM} ${NAME}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) deleted"

#valgrind: all
#	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all

.PHONY: all clean fclean re #valgrind
