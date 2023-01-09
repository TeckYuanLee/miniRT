NAME = minirt

GCC = gcc -Wall -Wextra -Werror -g3
OS_NAME := $(shell uname -s | tr A-Z a-z)
VALGRIND = valgrind --leak-check=full \
         --show-leak-kinds=all \
         --verbose \
         --log-file=valgrind-out.txt \
         --track-origins=yes \

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


INC = -Iinclude -Ilibft $(MLXINC)
LIB =  -L. -lminirt $(MLXLIB) -Llibft -lft


TEST_SRC = $(wildcard test/*.c)

SRC_DIRS = src src/hook src/utils src/vec_utils src/create
SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# SRC :=	$(addprefix src/, \
# 			render_image.c hit_sphere.c point_at_parameter.c parse_conf_file.c \
# 			$(addprefix hook/, \
# 				handle_key_release.c) \
# 			$(addprefix utils/, \
# 				put_pixel.c create_trgb.c render_gradient.c get_next_line.c) \
# 			$(addprefix vect_utils/, \
# 				 get.c set.c new_vect.c multi_div_sum_subtr.c multi_div_sum_subtr_d.c vec_math.c) \
# 		)

OBJDIR = obj/
OBJ := $(SRC:%.c=$(OBJDIR)%.o)
TEST_OBJ := $(TEST_SRC:%.c=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): main.c libminirt.a
	$(GCC) -o $@ main.c $(INC) $(LIB) 
	@printf "$(GREEN)$@ is ready to run$(NC)\n"

r: $(NAME)
	@printf "$(PINK) Running $<...$(NC)\n"
	@./$<

valgrind: $(NAME)
		$(VALGRIND) ./$< config/test.rt

libminirt.a: $(OBJ)
	@ar rcs $@ $^
	@printf "\033[0K\r$(GREEN)$@ compile successful!$(NC)\n"

test: $(TEST_OBJ)
	@$(GCC) $^ $(INC) $(LIB) -o $@exe
	@./$@exe
	@rm $@exe

$(OBJDIR)%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	@printf "Compiling $@ \033[0K\r"
	@$(GCC) -c $< $(INC) -o $@


clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re test

# Colors are great!
# Formats are greater!
# https://misc.flogisoft.com/bash/tip_colors_and_formatting
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[033m
BLUE	= \033[034m
PINK	= \033[035m
TEAL	= \033[036m
WHITE	= \033[037m
NC	= \033[0m # No Color