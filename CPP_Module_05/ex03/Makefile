NAME = intern

CXXPP = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(shell uname -s), Linux)
	CXXFLAGS = -Wall -Wextra -Werror -std=c++11
endif

RM = rm -f

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

%.o: %.cpp
	$(CXXPP) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXXPP) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
