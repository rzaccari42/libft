# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 15:33:14 by razaccar          #+#    #+#              #
#    Updated: 2023/11/27 17:20:56 by razaccar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = \
	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
	ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		\
	ft_memcpy.c		ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	\
	ft_strlcat.c	ft_toupper.c	ft_tolower.c	ft_strchr.c		\
	ft_strrchr.c	ft_strncmp.c	ft_memchr.c		ft_memcmp.c		\
	ft_strnstr.c	ft_atoi.c		ft_calloc.c		ft_strdup.c		\
	ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c		\
	ft_striteri.c	ft_strmapi.c	ft_itoa.c		ft_putchar_fd.c	\
	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c
B_SRC = \
	ft_lstnew.c		ft_lstadd_front.c ft_lstsize.c	ft_lstlast.c	\
	ft_lstadd_back.c ft_lstdelone.c   ft_lstclear.c ft_lstiter.c	\
	ft_lstmap.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

CC = gcc -c
CFLAGS = -Wall -Wextra -Werror
LIB = ar rc
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $@ $(OBJ)

bonus: $(OBJ) $(B_OBJ)
	$(LIB) $(NAME) $(OBJ) $(B_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $^

clean:
	$(REMOVE) $(OBJ) $(B_OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re