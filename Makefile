# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 16:19:53 by iseletsk          #+#    #+#              #
#    Updated: 2018/08/21 18:51:53 by iseletsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, get_lib

NAME = minishell

C = gcc

FLAGS += #-Wall -Wextra -Werror

LIBFT = ./libft/
LIB = ./libft/libft.a
SRC_DIR = src
OBJ = obj
INC = ./includes

SRC = 

SRC += main.c
SRC += ms_echo.c
SRC += ms_hendl_command.c
SRC += ms_pars_input.c
SRC += ms_cut_str_into_arg.c
SRC += ms_hendl_integrated_command.c
SRC += ms_exit.c
SRC += ms_del_arg_inp.c
SRC += ms_print_error.c
SRC += ms_cd.c
SRC += ms_cpy_environ.c
SRC += ms_env.c
SRC += ms_hendl_general_command.c
SRC += ms_create_path.c
SRC += ms_setenv.c
SRC += ms_unsetenv.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))
OBJS = $(addprefix $(OBJ)/,$(SRC:.c=.o))

all: get_lib $(NAME)

get_lib:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(C) $(FLAGS) -o $(NAME) $(OBJS) $(LIB) -I $(LIBFT) -I $(INC)

$(OBJ)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ)
	@$(C) $(FLAGS) -c -I $(LIBFT) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
