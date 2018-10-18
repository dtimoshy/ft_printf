#******************************************************************************#                                     
#                                                                              #                                     
#                                                         :::      ::::::::    #                                     
#    Makefile                                           :+:      :+:    :+:    #                                     
#                                                     +:+ +:+         +:+      #                                     
#    By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+         #                                     
#                                                 +#+#+#+#+#+   +#+            #                                     
#    Created: 2018/01/04 12:44:07 by dtimoshy          #+#    #+#              #                                     
#    Updated: 2018/01/05 12:26:17 by dtimoshy         ###   ########.fr        #                                     
#                                                                              #                                     
#******************************************************************************#                                     

NAME = libft.a

SRC =	get_next_line.c \
        ft_itoa_base.c \
        ft_atoi_base.c \
        ft_nbrlen.c \
        ft_abs.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
        ft_memcmp.c \
        ft_strlen.c \
        ft_strdup.c \
        ft_strcpy.c \
        ft_strncpy.c \
        ft_strcat.c \
        ft_strncat.c \
        ft_strlcat.c \
        ft_strchr.c \
        ft_strrev.c \
        ft_strrchr.c \
        ft_strstr.c \
        ft_strnstr.c \
        ft_strcmp.c \
        ft_strncmp.c \
        ft_atoi.c \
        ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_memalloc.c \
        ft_memdel.c \
        ft_strnew.c \
        ft_strdel.c \
        ft_strclr.c \
        ft_striter.c \
        ft_striteri.c \
        ft_strmap.c \
        ft_strmapi.c \
        ft_strequ.c \
        ft_strnequ.c \
        ft_strsub.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_putchar.c \
        ft_putstr.c \
        ft_putendl.c \
        ft_itoa.c \
        ft_putnbr.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_strsplit.c \
        ft_lstnew.c \
        ft_lstdelone.c \
        ft_lstdel.c \
        ft_lstadd.c \
        ft_lstiter.c \
        ft_lstmap.c \
        ft_isspace.c \
        ft_putstrarr.c \
        ft_lstaddend.c \
        ft_countword_delim.c \
        ft_strdelarr.c \
        ft_lstfind_nbr.c \
        ft_isblank.c \
        ft_iscntrl.c \
        ft_isgraph.c \
        ft_islower.c \
        ft_ispunct.c \
        ft_isupper.c \
        ft_lstinsert.c \
        ft_lstend.c \
        ft_lstlen.c \
        ft_lstreplace.c \
        ft_isnbr.c \
        ft_swap_nbr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -c

all:    $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
%.o:%.c
	@ gcc $< -o $@ $(CFLAGS)
clean:
	@ rm -f $(OBJ)
fclean: clean
	@ rm -f $(NAME)
re: fclean all