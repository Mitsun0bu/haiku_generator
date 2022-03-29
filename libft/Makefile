# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 14:36:18 by llethuil          #+#    #+#              #
#    Updated: 2022/03/21 22:30:26 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ COLOR CODES ~~~                             #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                              ~~~ VARIABLES ~~~                               #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

CC		:=	gcc

CFLAGS	:=	-Wall -Wextra -Werror

RM		:=	rm -f

INCS	:=	libft.h

SRCS	:=	ft_atoi.c				\
			ft_bzero.c				\
			ft_calloc.c				\
			ft_free_double_tab.c	\
			ft_itoa.c				\
			ft_memset.c				\
			ft_split.c				\
			ft_strdup.c				\
			ft_strjoin.c			\
			ft_strlen.c				\
			ft_strncmp.c			\

OBJS 	:= ${SRCS:.c=.o}

# **************************************************************************** #
#                                                                              #
#                              ~~~ RULES & COMMANDS ~~~                        #
#                                                                              #
# **************************************************************************** #

all: ${NAME}

.SILENT:

%.o: %.c libft.h Makefile
	${CC} ${CFLAGS} -I $(INCS) -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) libft/$<\n"

${NAME}: ${OBJS}
	printf "$(GREEN)> All the$(END) libft $(GREEN).c files have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the$(END) libft $(GREEN)archive file :$(END) $@\n"
	ar rcs $@ ${OBJS}
	printf "$(GREEN)>$(END) libft $(GREEN)archive has been compiled successfully !$(END)\n"

bonus: all

clean:
	${RM} ${OBJS}
	printf "$(PINK)> Removing$(END) libft $(PINK).o files ...$(END)\n"

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re