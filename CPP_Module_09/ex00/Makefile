NAME = btc

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(shell uname -s), Linux)
	CXXFLAGS = -Wall -Wextra -Werror -std=c++11
endif

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

RM = rm -f

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
