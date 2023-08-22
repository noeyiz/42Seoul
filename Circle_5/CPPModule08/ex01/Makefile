# compile options
NAME		= ex01
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

# source files
SRCS		= main.cpp	\
			  Span.cpp
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
	@$(CXX) $(CXXFLAGS) -c $<

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║                 CPP Module 08                 ║$(RESET)"
	@echo "$(GREEN)║             ex01 compile finished             ║$(RESET)"
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

build:
	@make all
	@make clean

.PHONY: all clean fclean re build

