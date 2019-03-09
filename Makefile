NAME = lem_in

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

SRC = main.c \
	  error.c \
	  get_info.c \
	  add_func.c \
	  print_file.c \
	  bfs.c \
	  debug.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_INC = $(LIBFT_DIR)
HEAD = $(INC_DIR)lem_in.h

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

CC_FLAGS = -g -Wall -Wextra -Werror 
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME) 
	@printf "\033[1;32mlem_in created \033[0m\n"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@printf "\033[1;33mobject deleted \033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@printf "\033[1;31mlem_in deleted \033[0m\n"

re: fclean all

.PHONY: all clean fclean re