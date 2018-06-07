NAME = fractol
CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror
SRC = *.c
OBJ = $(SRC:.c=.o)

GRAPHICS = -framework OpenGL -framework AppKit -lpthread
MLX_LNK = -L ./minilibx_macos -lmlx
FT_LNK = -L ./libft -lft

$(NAME):
	$(CC) $(CFLAGS) $(MLX_LNK) $(GRAPHICS) $(FT_LNK) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
