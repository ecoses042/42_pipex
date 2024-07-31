# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Name of the output executable
NAME = pipex

# Source files
SRC = main.c\
	utility/command_util.c\
	utility/ft_split.c\
	utility/ft_strcmp.c\
	utility/ft_strdup.c\
	utility/ft_strlen.c\
	utility/openfile.c\
	utility/print_error.c\
	utility/ft_strjoin.c\
	utility/free_str_arr.c\
# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link the object files into the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I.

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the executable
clean:
	rm -f $(OBJ)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
