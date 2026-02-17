NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
MLX_FILE	=	libmlx.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_FLAG	=	-lX11 -lXext
MLX_PATH	=	./minilibx-linux/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c ft_parsing.c ft_error.c ft_load_img.c ft_check_map.c ft_so_long_u.c ft_free.c flood_fill.c window.c ft_mlx_hook_init.c ft_draw_map.c ft_press.c flood_fill_two.c
SRC			=	$(addprefix ./, $(C_FILE))
OBJ			=	$(SRC:.c=.o)

RED			=	\033[0;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
BOLD		=	\033[1m
RESET		=	\033[0m

TOTAL_SRC	=	$(words $(SRC))
CURRENT		=	0

all: $(NAME)

lib: $(LIBFT_LIB)

$(LIBFT_LIB):
	@echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(BLUE)$(BOLD)COMPILING LIBFT$(RESET)"
	@echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@make -sC $(LIBFT_PATH)
	@echo "$(GREEN)LIBFT compiled successfully$(RESET)\n"

mlx: $(MLX_LIB)

$(MLX_LIB):
	@echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(BLUE)$(BOLD)COMPILING MLX$(RESET)"
	@echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@make -sC $(MLX_PATH)
	@echo "$(GREEN)MLX compiled successfully$(RESET)\n"

$(NAME): $(OBJ) | lib mlx
	@echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(BLUE)$(BOLD)LINKING SO_LONG$(RESET)"
	@echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(RESET)"
	@echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)\n"

%.o: %.c
	@$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@echo "$(BLUE)[$(CURRENT)/$(TOTAL_SRC)]$(RESET) $(YELLOW)Compiling$(RESET) $<"
	@$(CC) $(FLAGS) -c $< -o $@ -g

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@make clean -sC $(MLX_PATH) 2>/dev/null || true
	@make clean -sC $(LIBFT_PATH) 2>/dev/null || true
	@rm -f $(OBJ)
	@echo "$(GREEN)Object files removed$(RESET)\n"

fclean: clean
	@echo "$(YELLOW)Full clean (removing executables)...$(RESET)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) 2>/dev/null || true
	@echo "$(GREEN)Everything cleaned$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re lib mlx
