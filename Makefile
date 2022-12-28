NAME = minirt

GCC = gcc -Wall -Wextra -Werror -fsanitize=address -g3
OS_NAME := $(shell uname -s | tr A-Z a-z)
VALGRIND = valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \

MLXDIR = mlx/mlx-$(OS_NAME)
MLXINC :=
MLXLIB :=


ifeq ($(OS_NAME), mac)
	MLXINC += -I$(MLXDIR)
	MLXLIB += -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
endif

ifeq ($(OS_NAME), linux)
	MLXINC += -I/usr/include -I$(MLXDIR) -O3
	MLXLIB += -L$(MLXDIR) -lmlx -L/usr/lib -I$(MLXDIR) -lXext -lX11 -lm -lz
endif

FTINC = -Ilibft
FTLIB = -Llibft -lft

INC = -Iinclude $(FTINC) $(MLXINC)
LIB = $(MLXLIB) $(FTLIB)

DEPS = include/minirt.h

SRC_TEST = render_gradient.c

SRC = main.c put_pixel.c handle_key_release.c $(SRC_TEST)

vpath %.c src src/hook src/test

OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $^ $(LIB) -o $@

r : $(NAME)
	# $(VALGRIND) ./$<
	./$<

$(OBJDIR)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR)
	$(GCC) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	