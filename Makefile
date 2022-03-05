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
						src/component/OutputComponent.cpp			\
						src/Parser.cpp

SRC					+=	src/component/InputComponent.cpp			\
						src/component/inputs/TrueInput.cpp			\
						src/component/inputs/FalseInput.cpp			\
						src/component/inputs/Clock.cpp

SRC					+=	src/component/chipsets/And4081.cpp			\
						src/component/chipsets/Or4071.cpp			\
						src/component/chipsets/Not4069.cpp			\
						src/component/chipsets/FlipFlop4013.cpp		\
						src/component/chipsets/Counter4040.cpp		\
						src/component/chipsets/Johnson4017.cpp		\
						src/component/chipsets/Adder4008.cpp		\
						src/component/chipsets/Nand4011.cpp			\
						src/component/chipsets/Nor4001.cpp			\
						src/component/chipsets/Xor4030.cpp			\
						src/component/chipsets/Rom2716.cpp			\
						src/component/chipsets/Logger.cpp			\
						src/component/chipsets/Decoder4514.cpp		\
						src/component/chipsets/Selector4512.cpp		\
						src/component/chipsets/Ram4801.cpp			\
						src/component/chipsets/Shift4094.cpp		\
						src/component/chipsets/Proco4242.cpp		\
						src/component/chipsets/Gtx3090.cpp

TESTS_SRC			=	tests/TestsTools.cpp						\
						tests/NTSTests.cpp							\
						tests/GateTests.cpp							\
						tests/FlipFlopTests.cpp						\
						tests/DecoderTests.cpp						\
						tests/JohnsonTests.cpp

GCNO_FILES			=	$(SRC:.cpp=.gcno) $(TESTS_SRC:.cpp=.gcno)
GCDA_FILES			=	$(SRC:.cpp=.gcda) $(TESTS_SRC:.cpp=.gcda)

INC_DIR				=	./include

CXXFLAGS			+=	-Wall -Wextra -I$(INC_DIR)

MAIN_OBJ			=	$(MAIN_SRC:.cpp=.o)
OBJ					=	$(SRC:.cpp=.o)
TESTS_OBJ			=	$(TESTS_SRC:.cpp=.o)

NAME				=	nanotekspice
NAME_TESTS			=	unit_tests

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(OBJ)
	g++ $(CXXFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) -lsfml-window -lsfml-graphics -lsfml-system

tests_run: CXXFLAGS += --coverage
tests_run: fclean $(OBJ) $(TESTS_OBJ)
	g++ $(CXXFLAGS) -o $(NAME_TESTS) $(OBJ) $(TESTS_OBJ) -lcriterion
	./$(NAME_TESTS)

debug: CXXFLAGS += -g
debug: re

clean:
	rm -f $(MAIN_OBJ)
	rm -f $(OBJ)
	rm -f $(TESTS_OBJ)
	rm -f $(GCNO_FILES)
	rm -f $(GCDA_FILES)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

re: fclean all