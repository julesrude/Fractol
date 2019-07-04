NAME = fractol
SOURCES = main.c	actions_key.c	actions_mouse.c	draw_window.c	f_main.c	f_colors.c	f_pythagoras.c		bresenham.c		threads_calculation.c	bresenham_square.c	init_and_set.c
HEADER = includes/
OBJECTS = $(SOURCES:.c=.o)


LIBFT = libft/libft.a
LIBFT_FOLDER = libft
LIBFT_HEAD = libft/includes/

LIBX = minilibx/libmlx.a
LIBX_FOLDER = minilibx/

all: $(NAME)

$(NAME): $(LIBFT) $(LIBX) $(OBJECTS)
	@gcc $(OBJECTS) -I $(LIBFT_HEAD) $(LIBFT) -I $(HEADER) -L minilibx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lpthread -O1 -O2 -O3
	@echo "[ $(NAME) created ]"

$(LIBX):
	@make -C minilibx
	@echo "[ $(LIBX) created ]"

$(LIBFT):
	@make -C libft
	@echo "[ $(LIBFT) created ]"

%.o:%.c $(HEADER)
	@gcc -I $(LIBFT_HEAD) -I $(HEADER) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@make -C libft clean
	@echo "[ objects cleaned ]"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "[ $(NAME) and $(LIBFT) cleaned ]"

re: fclean all