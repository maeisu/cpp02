NAME = Fixed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = ./objs

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

vpath %.cpp 

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re