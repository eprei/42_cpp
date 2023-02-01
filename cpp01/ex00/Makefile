CXX = c++
# CXX = g++-12

NAME = BraiiiiiiinnnzzzZ

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

CFLAGS = -Werror -Wextra -Wall -std=c++98 #-pedantic # -g

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
