NAME := fractol

CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
#CFLAGS := -Wextra -Wall -Werror

LIBMLX := ./MLX42

LIBFT := ./libft

HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include

LIBS := $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm

SRCS := fractol.c utils.c mandelbrot.c julia.c

OBJS := ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
