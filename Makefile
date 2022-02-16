##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
## File description:
## Makefile
##

MAIN_SRC			=	src/main.cpp
SRC					=	src/NTS.cpp									\
						src/Tristate.cpp							\
						src/component/Component.cpp					\
						src/component/ComponentFactory.cpp			\
						src/component/Circuit.cpp					\
						src/component/OutputComponent.cpp

SRC					+=	src/component/InputComponent.cpp			\
						src/component/inputs/TrueInput.cpp			\
						src/component/inputs/FalseInput.cpp			\
						src/component/inputs/Clock.cpp

SRC					+=	src/component/chipsets/And4081.cpp			\
						src/component/chipsets/FlipFlop4013.cpp		\
						src/component/chipsets/Counter4040.cpp

INC_DIR				=	./include

CXXFLAGS			+=	-Wall -Wextra -I$(INC_DIR)

MAIN_OBJ			=	$(MAIN_SRC:.cpp=.o)
OBJ					=	$(SRC:.cpp=.o)

NAME				=	nanotekspice
NAME_TESTS			=	unit_tests

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(OBJ)
	g++ $(CXXFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ)

debug: CXXFLAGS += -g
debug: re

clean:
	rm -f $(MAIN_OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

re: fclean all