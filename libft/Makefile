# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: togibour <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/05 17:42:43 by togibour     #+#   ##    ##    #+#        #
#    Updated: 2018/04/10 18:58:32 by togibour    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

PATH_SRC = ./
PATH_OBJ = ./

FILES = ft_atoi ft_bzero ft_countwords ft_isalnum ft_isalpha ft_isascii\
		ft_isdigit ft_islower ft_isprint ft_isspace ft_isupper ft_itoa\
		ft_lstadd ft_lstat ft_lstcount ft_lstdel ft_lstdelone ft_lstiter\
		ft_lstmap ft_lstnew ft_lstpushback ft_lstshift ft_memalloc ft_memccpy\
		ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_nblen\
		ft_print_error ft_printbits ft_putchar ft_putchar_fd ft_putendl\
		ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_sqrt\
		ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup\
		ft_strequ ft_striter ft_striteri ft_strjoin ft_strjoini ft_strlcat\
		ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy\
		ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr\
		ft_strsub ft_strtrim ft_swapbits ft_tabchr ft_tolower ft_toupper\
		get_next_line

SRC = $(addprefix $(PATH_SRC), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c libft.h get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean
