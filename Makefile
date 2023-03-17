#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ncornacc <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/16 14:29:04 by ncornacc      #+#    #+#                  #
#    Updated: 2023/03/16 14:29:05 by ncornacc      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME	:=	client
NAME2	:=	server

HEAD	:= -I./includes/ -I./libft/include

LIBFT_D	:=	./libft

LIBFT	:=	${LIBFT_D}/libft.a

CC		:=	gcc

FLAGS	:=	-Wall -Werror -Wextra

RM		:=	rm	-rf

##############################################################
#############################SOURCES##########################

OBJ_DIR	:=	obj/
SRC_DIR	:=	src/

BON_DIR		:=	bonus/
BON_O_DIR	:=	obj_bonus/

FILE_B	:=	client_bonus
FILE2_B	:=	server_bonus

SRC2_B	:=	${addprefix ${BON_DIR}, ${addsuffix .c, ${FILE2_B}}}
OBJ2_B	:=	${addprefix ${BON_O_DIR}, ${addsuffix .o, ${FILE2_B}}}

SRC_B	:=	${addprefix ${BON_DIR}, ${addsuffix .c, ${FILE_B}}}
OBJ_B	:=	${addprefix ${BON_O_DIR}, ${addsuffix .o, ${FILE_B}}}

SRC2	:=	${addprefix ${SRC_DIR}, ${addsuffix .c, ${NAME2}}}
OBJ2	:=	${addprefix ${OBJ_DIR}, ${addsuffix .o, ${NAME2}}}

SRC		:=	${addprefix ${SRC_DIR}, ${addsuffix .c, ${NAME}}}
OBJ		:=	${addprefix ${OBJ_DIR}, ${addsuffix .o, ${NAME}}}

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

all:	${NAME} ${NAME2}

bonus:	${FILE_B} ${FILE2_B}

${FILE2_B}: ${LIBFT} ${OBJ2_B}
	@${CC} ${CFLAG} ${OBJ2_B} ${LIBFT} ${HEAD} -o ${FILE2_B}
	@echo "${GREEN} server_bonus compiled!${DEF_COLOR}"

${FILE_B}: ${LIBFT} ${OBJ_B}
	@${CC} ${CFLAG} ${OBJ_B} ${LIBFT} ${HEAD} -o ${FILE_B}
	@echo "${GREEN} client_bonus compiled!${DEF_COLOR}"

${NAME2}: ${LIBFT} ${OBJ2}
	@${CC} ${CFLAG} ${OBJ2} ${LIBFT} ${HEAD} -o ${NAME2}
	@echo "${GREEN} server compiled!${DEF_COLOR}"

${NAME}: ${LIBFT} ${OBJ}
	@${CC} ${CFLAG} ${OBJ} ${LIBFT} ${HEAD} -o ${NAME}
	@echo "${GREEN} client compiled!${DEF_COLOR}"

${BON_O_DIR}%.o: ${BON_DIR}%.c
	@mkdir -p ${BON_O_DIR}
	@echo	"${YELLOW} Compiling: $^ ${DEF_COLOR}"
	@${CC} ${FLAGS} ${HEAD} -c $< -o $@

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OBJ_DIR}
	@echo	"${YELLOW} Compiling: $^ ${DEF_COLOR}"
	@${CC} ${FLAGS} ${HEAD} -c $< -o $@

${LIBFT}:
	@make -C ${LIBFT_D}

clean:
	@make clean -C ${LIBFT_D}
	${RM} ${OBJ_DIR} ${BON_O_DIR}
	@echo "${MAGENTA} Object files cleaned!${DEF_COLOR}"

fclean: clean
	@make	fclean -C ${LIBFT_D}
	${RM}	${NAME} ${NAME2} ${FILE_B} ${FILE2_B} libft.a
	@echo  "${MAGENTA} executable/archive files cleaned!${DEF_COLOR}"

re:	fclean all
	@echo	"${GREEN} Cleaned and rebuild everything for Mini_talk!${DEF_COLOR}:"

.PHONY:	re all fclean clean

##############################################################