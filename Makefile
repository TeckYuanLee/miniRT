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

DEPS = include/minirt.h include/objects.h


SRC =	main.c render_image.c \
		$(addprefix src/, \
			$(addprefix hook/, handle_key_release.c) \
			$(addprefix utils/, put_pixel.c create_trgb.c render_gradient.c) \
			$(addprefix vect_utils/, get.c set.c new_vect.c multi_div_sum_subtr.c multi_div_sum_subtr_d.c) \
		)


OBJDIR = obj/
OBJ = $(SRC:$(notdir %.c)=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $^ $(LIB) -o $@

r : $(NAME)
	# $(VALGRIND) ./$<
	./$<

$(OBJDIR)%.o: %.c $(DEPS)
	mkdir -p $(dir $@)
	$(GCC) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	