CC = cc -no-pie
OBJA = build_map.o check_path_utils.o checks.o free_errors.o free_all.o get_textures.o gnl_utils.o key_hook.o libft_functions.o player_start.o center_of_mass.o
OBJA_PATH = $(patsubst %,$(SRC)%,$(OBJA))
OBJM = render_frame.o  so_long.o
OBJM_PATH = $(patsubst %,$(SRC)%,$(OBJM))
OBJB = render_frame_bonus.o so_long_bonus.o render_frame.o
OBJB_PATH = $(patsubst %,$(SRC)%,$(OBJB))
NAME = so_long

.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O0 -c $^ -o $@

$(NAME): $(OBJA_PATH) $(OBJM_PATH)
	cd minilibx-linux && make
	$(CC) $^ -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJA_PATH) $(OBJM_PATH) $(OBJB_PATH)

re: fclean all

bonus: $(OBJA_PATH) $(OBJB_PATH)
	$(CC) $^ -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
