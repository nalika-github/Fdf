# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 11:19:31 by ptungbun          #+#    #+#              #
#    Updated: 2023/02/01 10:58:05 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS_IMLX	= ./usr/include -Imlx_linux
HEADER		= fdf.h

# Variable declaration of directory
INCS_DIR	= ./includes
BUILD_DIR	= ./build
SRC_DIR		= ./srcs

# Variable declaration of file

SRCS		=	fdf_readfile.c main.c bresenham.c fdf_render.c \
				fdf_set_default.c fdf_rotate.c fdf_set_center.c \
				fdf_plotscr.c fdf_get_data.c fdf_interac.c fdf_key_hook.c \
				fdf_cleanup.c get_next_line_utils.c get_next_line.c \
				ft_bzero.c ft_atoi.c ft_split.c ft_putstr.c ft_tolower.c \

OBJS		=	$(SRCS:%.c=$(BUILD_DIR)/%.o)
MAIN		=	main.c

# Variable declaration of linking lib

MLXLINK		=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

# Build step for C source

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXLINK) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(INCS_IMLX) -c $< -o $@

bonus: all

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

test:
	$(CC) $(OBJS) $(MLXLINK) $(LIBLINK) -o $(NAME)
	@./runtest.out

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*c
	norminette -R CheckDefine $(INCS_DIR)/*h

.PHONY: all clean fclean re
