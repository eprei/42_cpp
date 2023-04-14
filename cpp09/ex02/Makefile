# CXX = c++
CXX = g++-12
# CXX = clang

NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp Vector.cpp Deque.cpp

CFLAGS = -Werror -Wextra -Wall -std=c++98 #-fsanitize=address #-g3 #-pedantic

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
