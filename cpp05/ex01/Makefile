CXX = c++
# CXX = g++-12

NAME = en_rang_les_larves

SRCS = main.cpp Bureaucrat.cpp Form.cpp

CFLAGS = -Werror -Wextra -Wall -std=c++98 #-g #-pedantic

OBJ = $(SRCS:.cpp=.o)

.cpp.o:
	$(CXX) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
