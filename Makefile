NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD
HEADERS = -I ./include
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = main.c \
		draw/animations.c draw/animations_2.c draw/dessins.c draw/draw_character.c draw/draw_content.c draw/draw_content_2.c \
		draw/draw.c draw/game_over.c draw/get_player_pictures.c draw/get_pictures.c draw/get_other_pictures.c \
		ft_printf/ft_printf.c ft_printf/ft_printf_utils1.c ft_printf/ft_printf_utils2.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		init/ft_flood_all.c init/ft_flood.c init/ft_preflood.c init/map_init_2.c init/map_init.c init/map_verif_2.c init/map_verif.c \
		init/root_init.c init/setup_ennemies.c init/check_lang.c\
		moves/keyboard_mouse.c moves/moves.c moves/lang_keybinds.c \
		utils/free_map.c utils/ft_itoa.c \
		
SRC_PATH = srcs/
MY_SOURCES := $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(MY_SOURCES:.c=.o)
MY_OBJECTS := $(addprefix build/, $(OBJ))
RM = rm -rf
DEPS := $(MY_OBJECTS:.o=.d)
MLX_PATH = mlx_linux/
MLX_LIB = $(MLX_PATH)libmlx.a

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		@make -sC $(MLX_PATH) all
		@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LFLAGS) -o $(NAME)

all: $(NAME)

clean:
		@make -C $(MLX_PATH) clean
		rm -rf build/srcs
		rm -rf build
		@$(RM) $(MY_OBJECTS)
		@$(RM) $(DEPS)

fclean: clean
		@$(RM) $(NAME)

re: fclean $(NAME)

build:
	@mkdir build
	@mkdir build/srcs
	@mkdir build/srcs/draw	
	@mkdir build/srcs/ft_printf
	@mkdir build/srcs/gnl
	@mkdir build/srcs/init
	@mkdir build/srcs/moves
	@mkdir build/srcs/utils

build/%.o: %.c | build
	@$(CC) $(CFLAGS) $(HEADERS) -I/usr/include -Imlx_linux -c $< -o $@

.PHONY : all clean fclean re libft

-include $(DEPS)
