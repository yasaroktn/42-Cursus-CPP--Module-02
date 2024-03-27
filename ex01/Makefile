NAME = Fixed

SRC = main.cpp Fixed.cpp

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(NAME)

re: clean all

fclean: 
	@$(RM) $(NAME)

.PHONY: all clean re