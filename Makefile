##
## EPITECH PROJECT, 2018
## libcsv
## File description:
## The library main Makefile.
##

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Iinclude -O2 -pipe
LDFLAGS = -L.

NAME = libcsv.a
TEST_NAME = unit-tests

SRCS = $(wildcard src/*.c) $(wildcard src/**/*.c)
OBJS = $(SRCS:.c=.o)
TEST_SRCS = $(wildcard test/*.c) $(wildcard test/**/*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: $(NAME)

$(NAME): CFLAGS += $(TEST_FLAGS)
$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

clean:
	$(RM) src/*.o src/*.gc* src/**/*.o src/**/*.gc*
	$(RM) test/*.o test/*.gc* test/**/*.o test/**/*.gc*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

$(TEST_NAME): TEST_FLAGS += -coverage
$(TEST_NAME): LDLIBS += -lcriterion -lgcov
$(TEST_NAME): $(NAME) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(LDFLAGS) $(LDLIBS)

test: $(TEST_NAME)
	./$^

re: fclean all

.PHONY: all clean fclean re test
