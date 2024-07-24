#fractol

NAME := fractol

OBJ_DIR := objs
MLX_DIR := ./MLX42
LIBFT := ./libft

HEADERS := -I ./include -I $(MLX_DIR)/include -I $(LIBFT)/include
LIBS := $(MLX_DIR)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm

SRCS := fractol.c utils.c mandelbrot.c julia.c ft_atof.c mouse.c pixels.c
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

RM := rm
CC := cc
MAKE := make
MAKE_DIR := mkdir

CFLAGS := -Wall -Wextra -Werror
LIB_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit $(LIBS) -g

all: libmlx libft $(NAME)

libmlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "MLX42 not found. Cloning..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	@echo "Start compiling MLX..."
	@cd $(MLX_DIR) && cmake -B build && $(MAKE) -C build -j4
	@echo "Done compiling MLX"

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "Successful build!"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(MLX_DIR)/build
	@$(MAKE) -C $(LIBFT) clean
	@echo "Bins successfully cleaned!"

fclean: clean
	@$(RM) -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(RM) -rf $(MLX_DIR)
	@echo "Everything successfully cleaned!"

re: fclean all

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(OBJ_DIR):
	@echo "Starting..."
	$(MAKE_DIR) $(OBJ_DIR)

.PHONY: all clean fclean re libmlx libft

