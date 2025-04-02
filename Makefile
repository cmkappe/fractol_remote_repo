NAME	=	fractol

SRC		= 	main.c render_fractol.c math.c helpers.c handle_keypress_and_mouse.c

SDIR 	= 	$(addprefix src/, $(SRC))

SOBJ	= 	$(SDIR:.c=.o)

HEADER	=	fractol.h

CC		= 	cc

FLAGS	= 	-Wall -Wextra -Werror -g -O2 -fsanitize=address

# for Mac compilation
LIB		= 	-framework OpenGL -framework AppKit

MLX		= 	-L$(MLXDIR) -lmlx

DYLIB	=	libmlx.dylib

MLXDIR	=	mlx

all: $(NAME)

$(NAME): $(SOBJ) $(MLX)
	$(CC) $(FLAGS) $(SOBJ) $(MLX) $(LIB) -o $(NAME)
	echo "\n\t   Fractol compliation successfull\n"

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(MLX):
	make -C $(MLXDIR)
	cp -rf $(MLXDIR)/$(DYLIB) .
	echo "\n\t   Minilibx compilation successfull\n"

clean:
	echo "\n\t   Cleaning\n"
	rm -rf $(SOBJ) $(BOBJ)
	make -C $(MLXDIR) clean

fclean: clean
	echo "\n\t   Cleaning successfull\n"
	rm -rf $(NAME) $(BONUS_NAME)
	rm -rf libmlx.dylib
	rm -rf screenshot.bmp

re:
	echo "\n\t   Remaking\n"
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus