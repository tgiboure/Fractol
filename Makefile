# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: togibour <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/07 12:06:49 by togibour     #+#   ##    ##    #+#        #
#    Updated: 2018/06/18 08:34:41 by togibour    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fractol
CC   = gcc
FLAGS= -Wall -Wextra -Werror

LIB = libft/libft.a
MLX = ./minilibx_macos/libmlx.a
INC_LIB = -L ./libft/ -l ft
INC_MLX = -L ./minilibx_macos/ -l mlx -framework OpenGL -framework AppKit -lpthread

PATH_SRC = ./src/
PATH_OBJ = ./src/

FILES = main ft_mandelbrot ft_image ft_hookfunc
SRC = $(addprefix $(PATH_SRC), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(MLX) $(LIB) $(OBJ)
	@$(CC) -o $(NAME) $(FLAG) $(OBJ) $(INC_LIB) $(INC_MLX)
	@echo "\033[1;37m                        __________________                               "
	@echo "\033[1;37m                        \____    /\_____  \                              "
	@echo "\033[1;37m                          /     /   _(__  <                              "
	@echo "\033[1;37m                         /     /_  /       \                             "
	@echo "\033[1;37m                        /_______ \/______  /                             "
	@echo "\033[1;37m                                \/       \/                              "
	@echo "\033[1;37m __________                                                  __          "
	@echo "\033[1;37m \______   \ ____ _____________   ____   ______ ____   _____/  |_  ____  "
	@echo "\033[1;37m  |       _// __ \\____ \_  __ \_/ __ \ /  ___// __ \ /    \   __\/ __ \ "
	@echo "\033[1;37m  |    |   \  ___/|  |_> >  | \/\  ___/ \___ \\  ___/|   |  \  | \  ___/ "
	@echo "\033[1;37m  |____|_  /\___  >   __/|__|    \___  >____  >\___  >___|  /__|  \___  >"
	@echo "\033[1;37m         \/     \/|__|               \/     \/     \/     \/          \/ "
	@echo "\033[37mFRACTOL COMPILED\033[0m"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c fractol.h
	@$(CC) $(FLAGS) -c $< -o $@

$(LIB):
	@make -C ./libft/
	@echo "\033[1;36m                        __________________                               "
	@echo "\033[1;36m                       <     LIBFT OK      >                             "
	@echo "\033[1;36m                        __________________                               "

$(MLX):
	@make -C ./minilibx_macos/
	@echo "\033[1;36m                        __________________                               "
	@echo "\033[1;36m                       <      MLX OK       >                             "
	@echo "\033[1;36m                        __________________                               "

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@make -C minilibx_macos clean
	@echo "\033[0;31m                        __________________                               "
	@echo "\033[0;31m                       <     Clean OK      >                             "
	@echo "\033[0;31m                        __________________                               "

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@make -C minilibx_macos fclean
	@echo "\033[1;31m                        __________________                               "
	@echo "\033[1;31m                       <     Fclean OK     >                             "
	@echo "\033[1;31m                        __________________                               "

re: fclean all
