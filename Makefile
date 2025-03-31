CC = gcc
FLAGS = -Wall -Wextra -g
TARGETS = stack.c main.c function.c circular_list.c browser.c
NAME = tema1

build: $(TARGETS)
	$(CC) $(FLAGS) -o $(NAME) $(TARGETS)

run: build
	./$(NAME)

PHONY: clean
clean:
	rm -f $(NAME)