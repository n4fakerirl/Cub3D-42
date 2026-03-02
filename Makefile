# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME        = cub3d
NAME_BONUS	= cub3d_bonus
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -Iincludes/libft -Iincludes/mlx_linux -g -O0
RM          = rm -f

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
VOID =  \033[2J

# **************************************************************************** #
#                                  DIRECTORIES                                 #
# **************************************************************************** #

SRC_DIR     = srcs/
SRC_DIR_BONUS = bonus/srcs/
OBJ_DIR     = objs/
OBJ_DIR_BONUS     = bonus/objs/
LIBFT_DIR   = includes/libft
MLX_DIR     = includes/minilibx-linux
# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_FILES   = main.c read_map.c free.c parse_ext.c parse_fc.c split.c divers.c \
				utils.c parse_map.c init.c window.c create_map.c \
				flood_fill.c
SRC_FILES_BONUS   = main.c read_map.c free.c parse_ext.c parse_fc.c split.c divers.c \
				utils.c parse_map.c print_map.c init.c window.c create_map.c \
				flood_fill.c
#SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
#OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS:$(SRC_DIR)/%=%))
SRCS_BONUS = $(shell find $(SRC_DIR_BONUS) -name '*.c')
OBJS_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c, $(OBJ_DIR_BONUS)/%.o, $(SRCS_BONUS:$(SRC_DIR_BONUS)/%=%))


# **************************************************************************** #
#                                   LIBRARIES                                  #
# **************************************************************************** #

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx_Linux.a

LIBS        = -L$(LIBFT_DIR) -lft \
            -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@$(MAKE) tabfast
	@sleep 0.1

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@$(MAKE) tabfast
	@sleep 0.1

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)


$(MLX):
	@$(MAKE) -sC $(MLX_DIR)

tabfast:
	@sleep 0.2
	@echo -n "\n\r[$(YELLOW)....$(RESET)]"
	@sleep 0.2
	@echo -n "\r[$(MAGENTA)//..$(RESET)]"
	@sleep 0.2
	@echo -n "\r[$(RED)////$(RESET)]"
	@sleep 0.05
	@echo -n "\r[$(GREEN)✓✓✓✓$(RESET)]"
	@sleep 0.1
	@echo "\n\n$(GREEN)CUB3D COMPILED$(RESET)\t\n"

clean:
	@$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean
	@echo "$(MAGENTA)🧹 Cleaning objects...$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@echo "$(GREEN)🗑️ Cleaning objects and executable...$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
