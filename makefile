NAME = program

SOURCES = srcs/Objects.cpp srcs/main.cpp srcs/Window.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SOURCES:.cpp=.o)
HEADER = headers/Objects.hpp headers/Window.hpp

%.o: %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -lGL -lGLU -lglut -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
