NAME = program

SOURCES = srcs/Objects.cpp srcs/main.cpp srcs/Window.cpp srcs/Base.cpp
FLAGS = -Wall -Wextra -Werror
OBJ = $(SOURCES:.cpp=.o)
HEADER = headers/Objects.hpp headers/Window.hpp headers/Base.hpp

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
