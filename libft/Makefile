#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ncornacc <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/11 11:34:37 by ncornacc      #+#    #+#                  #
#    Updated: 2023/02/03 14:15:40 by ncornacc      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

#############################VARIABLES################################

NAME	:=	libft.a

INCLUDE	:=	-I./include/

ARR		:=	ar -rc

CC		:=	gcc

FLAGS	:=	-Wall -Werror -Wextra 

RM		:=	rm	-rf

##############################################################
#############################SOURCES##########################

OBJ_DIR	:=	obj/
SRC_DIR	:=	src/

SRC		:=	$(wildcard ${SRC_DIR}/*.c)
OBJ		:=	${addprefix ${OBJ_DIR}, ${notdir ${SRC:.c=.o}}}


##############################################################
#############################COLORS###########################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m

##############################################################
#############################RULES############################

all:	${NAME}

${NAME}: ${OBJ_DIR} ${OBJ}
	@${ARR} ${NAME}	${OBJ}
	@echo "${GREEN} libft.a compiled!${DEF_COLOR}"

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@echo	"${YELLOW} Compiling: $^ ${DEF_COLOR}"
	@${CC} ${FLAG} ${INCLUDE} -c $^ -o $@

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

clean:
	${RM} ${OBJ_DIR}
	@echo "${MAGENTA} Object files cleaned!${DEF_COLOR}"

fclean:		clean
	${RM} ${NAME}
	@echo  "${MAGENTA} executable/archive files cleaned!${DEF_COLOR}"

re:		fclean all
		@echo	"${GREEN} Cleaned and rebuild everything for libft!${DEF_COLOR}:"

.PHONY:		all clean fclean re