# compile options
NAME		= unnecessary_violence
CC			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

# source files
SRCS		= main.cpp	 \
			  Weapon.cpp \
			  HumanA.cpp \
			  HumanB.cpp
OBJS		= $(SRCS:.cpp=.o)

# colors
RESET		= \033[0m
GRAY		= \033[1;90m
RED			= \033[1;91m
GREEN		= \033[1;92m
YELLOW		= \033[1;93m
BLUE		= \033[1;94m
MAGENTA		= \033[1;95m
CYAN		= \033[1;96m

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CXXFLAGS) -c $<

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║                 CPP Module 01                 ║$(RESET)"
	@echo "$(GREEN)║             ex03 compile finished             ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(CYAN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║              make clean finished              ║$(RESET)"
	@echo "$(CYAN)╚═══════════════════════════════════════════════╝$(RESET)"

fclean:
	@make clean
	@$(RM) $(NAME)
	@echo "$(CYAN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║              make fclean finished             ║$(RESET)"
	@echo "$(CYAN)╚═══════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
