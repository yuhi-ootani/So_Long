# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 10:39:54 by oyuhi             #+#    #+#              #
#    Updated: 2025/01/12 14:04:40 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
# -L :Specifies a directory to search for libraries.
# -l :Specifies the name of the library to link. -l<library_name> = -l lib<library_name>.a

# MiniLibX for Linux requires xorg, x11 and zlib
# -lXext and -lX11: Links X11 libraries required for graphical output.
#  xorg : Indirect Linking via libX11 and libXext to the display server manages graphical displays and input devices.
#  -lz: Links the zlib compression library (used by MiniLibX for certain XPM-related operations).

# -lm : math library
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lz -lm
LIBFT = libft/libft.a


SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objs

SRCS = $(wildcard $(SRC_DIR)/*.c) 
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

	

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

#-C :Change Directory.
$(LIBFT):
	make -C libft

# Create the object directory if it doesn't exist
# -p:  mkdir would raise an error if the directory already exists. The -p flag avoids this issue.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@
# -O3: Enables high-level optimizations which can make your program run faster 
#but may increase compilation time and make debugging more challenging.

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re