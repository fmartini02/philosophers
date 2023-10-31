# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmartini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:56:17 by fmartini          #+#    #+#              #
#    Updated: 2023/09/04 18:17:57 by fmartini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -g

SRC := \
        ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
        ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
        ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
        ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c \
        ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
        ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c \
        ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c \
        ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
        get_next_line.c get_next_line_utils.c\
        ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
        ft_lstlast.c ft_lstadd_back.c \
		ft_strjoin_free.c ft_adv_fun.c \
        ft_base_fun.c ft_printf.c ft_put_hexa.c ft_strcpy.c \
        ft_strcmp.c ft_strstr.c  
        

OBJ_S = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_S)
	@ ar -rcs $@ $^

.o: %.c
	@ $(CC) -c $(CFLAG) -I. $< -o $@

clean:
	@ /bin/rm -f *.o

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
