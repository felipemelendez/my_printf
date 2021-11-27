FLAGS = -Wall -Werror -Wextra 
NAME = my_printf
SRC = *.c
OBJECTS = *.o
SANITIZE = -fsanitize=address -g3

print: $(SRC)
	gcc $(FLAGS) $(SANITIZE) $(SRC) -o my_printf && ./my_printf

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
