##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
## File description:
## Makefile
##

MAIN_SRC			=	src/main.cpp
SRC					=	src/Tristate.cpp							\
						src/component/Component.cpp					\
						src/component/Circuit.cpp					\
						src/component/chipsets/Chipset4081.cpp		\
						src/component/chipsets/TrueFalse.cpp		\
						src/component/chipsets/Clock.cpp			\
						src/component/chipsets/Output.cpp

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

clean: SRC += MAIN_SRC
clean:
	rm -f $(MAIN_OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

re: fclean all