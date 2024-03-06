# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 11:18:01 by dferreir          #+#    #+#              #
#    Updated: 2023/08/24 10:38:15 by dferreir         ###   ########.fr        #
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
NAME		= Fix

#FILES
HEADS_LIST	= Fixed.hpp
HEADS_DIR	= ./incs/
HEADS		= $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SRCS_DIR	= ./srcs/
SRCS_FILES	= main.cpp Fixed.cpp
SRCS		:= ${addprefix ${SRCS_DIR}, ${SRCS_FILES}}

OBJS_DIR	= ./objs/
OBJS_FILES	:= ${SRCS_FILES:.cpp=.o}
OBJS		:= ${addprefix ${OBJS_DIR}, ${OBJS_FILES}}

#COMMANDS
CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
AR			= ar rcs
MKDIR		= mkdir -p
RM			= rm -rf
LIBS		= -lft -L$(LIBFT_DIR)
INCS		= -I$(HEADS_DIR)

all: ${NAME}

#Compile normal executable
${NAME}: ${OBJS_DIR} ${OBJS}
	@${CC} ${CFLAGS} ${INCS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) created and compiled object files"
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) is ready"

#Create objects directory
${OBJS_DIR}:
	@${MKDIR} ${OBJS_DIR}

#Compile normals objects
${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
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
