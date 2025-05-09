CC = gcc
FLAGS = -Wall -Wextra -g
TARGETS = stack.c main.c function.c circular_list.c browser.c
NAME = tema1

build: $(TARGETS)
	$(CC) $(FLAGS) -o $(NAME) $(TARGETS)

run: build
	./$(NAME)

pack:
	zip -FSr NEACSALeonard-315CA.zip README Makefile *.c *.h

PHONY: clean
clean:
	rm -f $(NAME)