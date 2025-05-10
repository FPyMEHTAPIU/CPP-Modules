#colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = phonebook

SRCS = \
	Contact.cpp \
	PhoneBook.cpp \
	main.cpp \
	utils.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -std=c++20 -Wall -Werror -Wextra

RM = rm -rf

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)🛠  Compiling phonebook... 🛠$(DEF_COLOR)"
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)🥳 Success!🥳$(DEF_COLOR)"

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)🚽 Deleting object files... 🚽$(DEF_COLOR)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)🪦 Deleting phonebook... 🪦$(DEF_COLOR)"
	@$(RM) $(NAME)
	@echo "$(RED)☣️  CLEAR ☣️$(DEF_COLOR)"

re: fclean all