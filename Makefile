NAME := libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC_DIR := src/
INC_DIR := inc/
OBJ_DIR := obj/

LIBFT_DIR := ./libft/
LIBFT_OBJ := $(LIBFT_DIR)/*.o
LIBFT_INC := $(LIBFT_DIR)

SRC := \
ft_printf.c\
parse_convert.c\
handle_d.c \
handle_u.c \
handle_o.c \
handle_x.c \
handle_p.c \
handle_bx.c \
handle_other.c \
handle_char.c \
handle_string.c \
num_helper.c \
char_helper.c


OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(OBJ_DIR) $(OBJ)
	@ ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
	@ ranlib $(NAME)

$(OBJ_DIR):
	@ mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ gcc -c $(CFLAGS) $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

$(LIBFT_OBJ):
	@ make -C $(LIBFT_DIR)

clean:
	@ rm -f $(OBJ)
	@ rm -rf $(OBJ_DIR)
	@ make clean -C $(LIBFT_DIR)

fclean: clean
		@ rm -f $(NAME)
		@ make fclean -C $(LIBFT_DIR)

re: fclean all
