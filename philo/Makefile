# ---------------------------------------------
# SETTINGS
# ---------------------------------------------
NAME		:=	philo
CC			:=	cc
CFLAGS		:=	-Werror -Wextra -Wall
INCLUDE_DIR	:=	./inc
OBJECT_DIR	:=	./obj

# ---------------------------------------------
# SOURCES
# ---------------------------------------------
SOURCE_DIRS	:=	src src/utils
VPATH		:= 	$(SOURCE_DIRS)
SOURCES		:=	main.c ft_atoi.c ft_isdigit.c ft_strchr.c
OBJECTS		:=	$(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

# ---------------------------------------------
# COLORS
# ---------------------------------------------
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

# ---------------------------------------------
# RULES
# ---------------------------------------------
all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(YELLOW)Compiling $(NAME)$(NC)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Successfully compiled $(NAME)$(NC)"

$(OBJECT_DIR)/%.o: %.c | $(OBJECT_DIR)
	@printf "$(YELLOW)Compiling $(CYAN)$<\n$(NC)"
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)
	@echo "$(YELLOW)Created obj directory$(NC)"

clean:
	@rm -rf $(OBJECT_DIR)
	@echo "$(RED)Removed object files$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re


