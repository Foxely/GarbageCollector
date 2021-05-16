##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make an executable
##

CC = gcc
TARGET_EXEC ?= foxely

SRC_DIRS = ./tiny_garbage

SRC = $(shell find $(SRC_DIRS) -name '*.c')
MAIN = main.c
OBJS = $(MAIN:%.c=%.o) $(SRC:%.c=%.o)
CFLAGS += -W -Wall $(if $(DEBUG),-g3)
LDFLAGS = -L./list -llist
INC_FLAGS = -Iinclude

TEST_NAME = unit_tests
UNIT_SRC =	$(shell find asm -name '*.c')


TEST_SRC =	$(shell find tests -name '*.c')




all: lib $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	@$(CC) -o $@ $(OBJS) $(CFLAGS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(INC_FLAGS) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32mCompiled \033[1;37m'$<'\033[m"

.PHONY: clean
clean:
	@$(RM) -r main.o
	@$(RM) -r $(OBJS)
	@$(RM) -r *.gcno
	@$(RM) -r *.gcda
	@$(RM) -r "NUL"

.PHONY: fclean
fclean: lib_fclean clean
	@$(RM) -r $(TARGET_EXEC)
	@$(RM) -r $(TEST_NAME)
	@$(RM) -r vgcore*

.PHONY: re
re: fclean all

valgrind:
	valgrind --leak-check=full -s ./$(NAME)

lib:
	@make -sC list

lib_fclean:
	@make fclean -sC list