NAME := Form
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic
SRC := main.cpp Bureaucrat.cpp Form.cpp
OBJ := $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

format:
	clang-format -i *.h *.cpp

linter:
	clang-tidy *cpp --extra-arg="-isysroot" --extra-arg="$(xcrun --show-sdk-path)" -- -I. -std=c++98

re: fclean all

.PHONY: all clean re fclean format
