NAME = fixed

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -I includes

SRC_DIR = src/
OBJ_DIR = obj/

SRC =	$(addprefix $(SRC_DIR), main.cpp Fixed.cpp)
OBJS = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@printf "$(GREEN)[Compiling]$(NC) %s...$(NC)\n" "$(notdir $(<))"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(RED)[Cleaning]$(NC)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re