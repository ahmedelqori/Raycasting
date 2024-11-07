GREEN = \033[1;3;32m
RED = \033[1;3;31m
YELLOW=\033[1;3;33m
RESET = \033[0m
MAGENTA = \033[1;35m
BLUE = \033[34;1;3m

CC = cc
NAME = cub3D
NAME_BONUS = cub3D_bonus

CFLAGS = -Wall -Wextra  -Werror  #-fsanitize=address -g

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx
MLX= $(MLX_PATH)/libmlx.a

SRC = ./src/main.c \
	./src/parsing/ft_parsing.c \
	./src/execution/reset_values.c \
	./src/execution/background_drawing.c \
	./src/execution/main_execution.c \
	./src/execution/movement_logic.c \
	./src/execution/error_handling.c \
	./src/execution/default_configuration.c \
	./src/execution/key_event_processing.c \
	./src/execution/render_engine.c \
	./src/execution/asset_manager.c \
	./src/execution/raycasting.c \
	./src/execution/raycast_math.c \
	./src/execution/draw_images.c \
	./src/execution/ray_hit_the_wall.c \
	./src/parsing/ft_normalize_map.c \
	./src/parsing/ft_verify_map.c \
	./src/parsing/ft_utils.c \
	./src/parsing/ft_verify_floor_ceil.c \
	./src/parsing/ft_verify_textures.c \
	./src/parsing/ft_verify_data.c \
	./src/parsing/ft_verify_content.c \
	./src/parsing/ft_free_parsing.c \
	./src/parsing/upload_content.c \
	./src/parsing/utils.c \
	./src/parsing/get_next_line.c \
	./src/parsing/get_next_line_utils.c

SRC_BONUS = ./src_bonus/main_bonus.c \
	./src_bonus/parsing/ft_parsing_bonus.c \
	./src_bonus/execution/reset_values_bonus.c \
	./src_bonus/execution/background_drawing_bonus.c \
	./src_bonus/execution/main_execution_bonus.c \
	./src_bonus/execution/movement_logic_bonus.c \
	./src_bonus/execution/error_handling_bonus.c \
	./src_bonus/execution/default_configuration_bonus.c \
	./src_bonus/execution/key_event_processing_bonus.c \
	./src_bonus/execution/render_engine_bonus.c \
	./src_bonus/execution/asset_manager_bonus.c \
	./src_bonus/execution/raycasting_bonus.c \
	./src_bonus/execution/raycast_math_bonus.c \
	./src_bonus/execution/draw_images_bonus.c \
	./src_bonus/execution/ray_hit_the_wall_bonus.c \
	./src_bonus/execution/draw_mini_map_bonus.c\
	./src_bonus/execution/open_close_doors_bonus.c\
	./src_bonus/execution/handle_mouse_bonus.c\
	./src_bonus/execution/gun_animation_bonus.c\
	./src_bonus/parsing/ft_normalize_map_bonus.c \
	./src_bonus/parsing/ft_verify_map_bonus.c \
	./src_bonus/parsing/ft_utils_bonus.c \
	./src_bonus/parsing/ft_verify_floor_ceil_bonus.c \
	./src_bonus/parsing/ft_verify_textures_bonus.c \
	./src_bonus/parsing/ft_verify_data_bonus.c \
	./src_bonus/parsing/ft_verify_content_bonus.c \
	./src_bonus/parsing/ft_free_parsing_bonus.c \
	./src_bonus/parsing/upload_content_bonus.c \
	./src_bonus/parsing/utils_bonus.c \
	./src_bonus/parsing/get_next_line_bonus.c \
	./src_bonus/parsing/get_next_line_utils_bonus.c

LIB = ./includes/cub.h ./includes/includes.h ./includes/macros.h ./includes/prototypes.h \
	./includes/structures.h

LIB_BONUS = ./includes_bonus/cub_bonus.h ./includes_bonus/includes_bonus.h ./includes_bonus/macros_bonus.h ./includes_bonus/prototypes_bonus.h \
	./includes_bonus/structures_bonus.h



OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(MLX) $(LIBFT) $(NAME)
	@echo -n;

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) -Lminilibx -lmlx -lXext -lX11 -lm $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)\t\t✓ $(NAME)$(RESET)"
	@echo "$(MAGENTA)Usage:\n\t$(YELLOW)./cub3D map.cub$(RESET)"
	

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)\t\t✓ libft$(RESET)"
$(MLX):
	@$(MAKE) -C $(MLX_PATH) > /dev/null
	@echo "$(GREEN)\t\t✓ mlx$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -Iminilibx  -c $< -o $@

bonus: $(MLX) $(LIBFT) $(NAME_BONUS)
	@echo -n;

$(NAME_BONUS): $(LIB_BONUS) $(OBJ_BONUS) 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -Lminilibx -lmlx -lXext -lX11 -lm  $(LIBFT) $(MLX) -o $(NAME_BONUS)
	@echo "$(GREEN)\t\t✓ $(NAME_BONUS)$(RESET)"
	@echo "$(MAGENTA)Usage:\n\t$(YELLOW)./cub3D_bonus map.cub$(RESET)"

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "$(RED)\t\t✓ deleted objects $(NAME)$(RESET)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted objects libft$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)\t\t✓ deleted $(NAME) $(NAME_BONUS)$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@$(MAKE) clean -C $(MLX_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted libft$(RESET)"
	@echo "$(RED)\t\t✓ deleted mlx$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
