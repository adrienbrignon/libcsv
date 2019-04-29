##
## EPITECH PROJECT, 2018
## libcsv
## File description:
## The library main Makefile.
##

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Iinclude -O2 -pipe

NAME = libcsv.a

SRCS = $(wildcard src/*.c) $(wildcard src/**/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): CFLAGS += $(TEST_FLAGS)
$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

clean:
	$(RM) src/*.o src/*.gc* src/**/*.o src/**/*.gc*

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
