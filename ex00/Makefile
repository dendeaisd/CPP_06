NAME    := convert
CC      := c++
FLAGS   := -Wall -Wextra -Werror -std=c++17
SRC     := main.cpp ScalarConverter.cpp
OBJDIR  := obj
OBJ     := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

# Colors
YELLOW  := \033[38;2;204;204;0m
ORANGE  := \033[38;2;255;87;34m
RESET   := \033[0m

# Cursor manipulation
UP      := \033[A
CUT     := \033[K
BEGIN   := \033[0G

all     : $(NAME)

$(NAME) 	: $(OBJ)
	@python3 anim.py &
	@ANIMATION_PID=$$!;
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@sleep 6.9
	@touch stop_animation.txt
	@wait $$ANIMATION_PID 2>/dev/null

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : %.cpp | $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean   :
	@echo "$(UP)$(BEGIN)$(CUT)$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean  :
	@echo "$(UP)$(BEGIN)$(CUT)$(ORANGE)🔥 Full clean, removing executable...$(RESET)"
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re      : fclean all

.PHONY  : all clean fclean re
.PHONY 		: all clean fclean re
