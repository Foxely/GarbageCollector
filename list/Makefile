##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make an executable
##

NAME		=	liblist.a

CC		=	gcc

RM		=	rm -f

COMPILEFLAGS	=	-std=gnu11 -Wall -Wextra -O3

INCLUDES	=	.

LDFLAGS		=	

CFLAGS		=	$(COMPILEFLAGS) -I ./$(INCLUDES)

SRCPATH		=	.

SRCS		=	$(SRCPATH)/list_add.c	\
			$(SRCPATH)/list_delete.c	\
			$(SRCPATH)/list_get.c	\
			$(SRCPATH)/list_getnode.c	\
			$(SRCPATH)/list_utils.c	\

OBJS		=	$(SRCS:.c=.o)

DEBUG		=	no

ifeq ($(DEBUG), yes)
CC		=	g++
CFLAGS		+=	 -g3 -std=gnu11 -Wall -Wextra
LDFLAGS		+=	
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo -n "\033[0;34mCompilation en cours...\033[0m\n"
	@ar -rc $(NAME) $(OBJS)
	printf "\033[0;32mCompilation terminée avec succès.\033[0m\n"

clean:
	$(RM) $(OBJS)
	printf "\033[0;33mSuppression des \".o\"...\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	printf "\033[0;33mSuppresion du binaire...\033[0m\n"

re: fclean all

