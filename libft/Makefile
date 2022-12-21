NAME = libft.a

CC = gcc -Wall -Werror -Wextra

SRCS := $(shell find . ! -name ft_lst\* -name ft\*.c)
BONUS_SRCS := $(shell find . -name ft_lst\*.c)
DEPS = libft.h

all: $(NAME)
	@echo "libft.a not available, compiling now..."

$(NAME): $(SRCS:.c=.o)
	@ar rcs $@ $^
	@echo "${GREEN}libft.a compile successful!${NC}"

bonus: $(BONUS_SRCS:.c=.o)  $(SRCS:.c=.o)
	@ar rcs $(NAME) $^
	@echo "${GREEN}libft.a with bonus compile successful!${NC}"
	
%.o: %.c $(DEPS)
	@$(CC) -c $<

so:
	$(CC) -nostartfiles -fPIC $(SRCS) $(BONUS_SRCS)
	gcc -nostartfiles -shared -o libft.so *.o

test: $(NAME) bonus
	@$(CC) test.c -L. -lft && ./a.out

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m # No Color