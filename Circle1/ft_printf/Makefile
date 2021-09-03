NAME = ft_printf.a
HEADER = ft_printf.h
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
SOURCES = ft_printf.c \
			format.c \
			parse.c \
			utils.c \
			utils2.c

BONUS_SRCS = ft_printf.c \
			format.c \
			parse.c \
			utils.c \
			utils2.c


OBJS = $(SOURCES:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
    OBJECTS = $(OBJS) $(BONUS_OBJS)
else
    OBJECTS = $(OBJS)
endif

.PHONY : all
all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) $@ $^

.PHONY : bonus
bonus :
		make WITH_BONUS=1 all

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

.PHONY : fclean
fclean: clean
	$(RM) $(NAME)

.PHONY : re
re: fclean all
