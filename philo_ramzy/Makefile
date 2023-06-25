#Define the compiler
CC = cc

# Define the flags to pass to the compiler
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

# Define the source files for the philo executable
SRC = philosophers.c ./utils/ft_atoi.c ./utils/ft_usleep.c ./utils/actions.c ./utils/meals.c

# Define the object files for the philo executable, generated from the source files
OBJ = $(SRC:.c=.o)

# Define the name of the philo executable to be generated
NAME = philo

# Define the default target to be built
all: $(NAME)

# Rule to generate the philo executable from the object files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to generate the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.c,%.o,$<)

# Clean target to remove generated files
clean:
	rm -f $(OBJ)

# Fclean target to remove executable files and perform clean
fclean: clean
	rm -f $(NAME)

# Re target to rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
