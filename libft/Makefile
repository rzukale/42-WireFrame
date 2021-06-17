# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:23:58 by rzukale           #+#    #+#              #
#    Updated: 2020/02/29 10:55:53 by rzukale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_atoi.c           \
        ft_bzero.c          \
        ft_isalnum.c        \
        ft_isalpha.c        \
        ft_isascii.c        \
        ft_isdigit.c        \
        ft_isprint.c        \
        ft_itoa.c           \
        ft_memalloc.c       \
        ft_memccpy.c        \
        ft_memchr.c         \
        ft_memcmp.c         \
        ft_memcpy.c         \
        ft_memdel.c         \
        ft_memmove.c        \
        ft_memset.c         \
        ft_putchar.c        \
        ft_putchar_fd.c     \
        ft_putendl.c        \
        ft_putendl_fd.c     \
        ft_putnbr.c         \
        ft_putnbr_fd.c      \
        ft_putstr.c         \
        ft_putstr_fd.c      \
        ft_strcat.c         \
        ft_strchr.c         \
        ft_strclr.c         \
        ft_strcmp.c         \
        ft_strcpy.c         \
        ft_strdel.c         \
        ft_strdup.c         \
        ft_strequ.c         \
        ft_striter.c        \
        ft_striteri.c       \
        ft_strjoin.c        \
        ft_strlcat.c        \
        ft_strlen.c         \
        ft_strmap.c         \
        ft_strmapi.c        \
        ft_strncat.c        \
        ft_strncmp.c        \
        ft_strncpy.c        \
        ft_strnequ.c        \
        ft_strnew.c         \
        ft_strnstr.c        \
        ft_strrchr.c        \
        ft_strsplit.c       \
        ft_strstr.c         \
        ft_strsub.c         \
        ft_strtrim.c        \
        ft_tolower.c        \
        ft_toupper.c        \
        ft_lstnew.c     \
        ft_lstdelone.c  \
        ft_lstdel.c     \
        ft_lstadd.c     \
        ft_lstiter.c    \
        ft_lstmap.c     \
        ft_int_length.c \
        ft_isspace.c    \
        ft_isupper.c    \
        ft_islower.c    \
        ft_strndup.c    \
        get_next_line.c

OBJ = $(SRC:.c=.o)
SRC_DIR = srcs
OBJ_DIR = objs
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
HEADER = -I includes
CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(OBJS): $(SRCS)
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(SRCS) $(HEADER)
	mv $(OBJ) $(OBJ_DIR)

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.PRECIOUS: author
