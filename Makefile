# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 23:12:01 by llethuil          #+#    #+#              #
#    Updated: 2022/03/21 22:28:58 by llethuil         ###   ########lyon.fr    #
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

NAME			:=	haiku_generator

CC				:=	gcc

CFLAGS			:=	-Wall -Werror -Wextra

RM				:=	rm

LIBFT_DIR		:=	libft

INCS_DIR		:=	incs

SRCS_DIR		:=	srcs

OBJS_DIR		:=	.objs

INCS_LST		:=	haiku_generator.h	\

SRCS_LST		:=	haiku_generator.c	\

OBJS_LST		:=	$(SRCS_LST:.c=.o)

LIBFT_AR		:=	$(LIBFT_DIR)/libft.a

INCS			:=	$(addprefix $(INCS_DIR)/, $(INCS_LST))

SRCS			:=	$(addprefix $(SRCS_DIR)/, $(SRCS_LST))

OBJS			:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

# ************************************************************************** #
#                                                                            #
#                              ~~~ RULES & COMMANDS ~~~                      #
#                                                                            #
# ************************************************************************** #

.SILENT:

all:	libft $(NAME)

.SILENT:

libft:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_AR)
	test -z '$(filter %.o,$?)' || printf "$(GREEN)> All the .c files from$(END) $(NAME) $(GREEN)have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	printf "$(PINK)> Removing$(END) $(NAME) $(PINK).o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing$(END) $(OBJS_DIR) $(PINK)directory ...$(END)\n"
	rm -rf $(OBJS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing$(END) libft $(PINK)archive file ...$(END)\n"
	$(RM) $(LIBFT_AR)
	printf "$(PINK)> Removing$(END) $(NAME) $(PINK)executable file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(GREEN)>$(END) libft $(GREEN)archive and$(END) $(NAME) $(GREEN)executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean libft re
