#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:15:55 by dborysen          #+#    #+#              #
#    Updated: 2017/12/06 11:39:24 by dborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_count_digit_u.c get_next_line.c ft_putllu.c ft_putlonglong.c ft_lowstr.c ft_itoa_base.c ft_reverse_bits.c ft_ispower.c ft_isvalid.c ft_atoi.c ft_lstmap.c ft_putendl.c ft_strdel.c ft_strncpy.c ft_bzero.c ft_lstnew.c ft_putendl_fd.c ft_strdup.c ft_strnequ.c ft_isalnum.c ft_memalloc.c ft_putnbr.c ft_strequ.c	ft_strnew.c ft_isalpha.c ft_memccpy.c ft_putnbr_fd.c ft_striter.c ft_strnstr.c ft_isascii.c ft_memchr.c ft_putstr.c ft_striteri.c	ft_strrchr.c ft_isdigit.c	ft_memcmp.c ft_putstr_fd.c ft_strjoin.c ft_strsplit.c ft_isprint.c ft_memcpy.c ft_shwlst.c	ft_strlcat.c	ft_strstr.c ft_itoa.c	ft_memdel.c ft_strcat.c ft_strlen.c ft_strsub.c ft_lstadd.c ft_memmove.c ft_strchr.c ft_strmap.c ft_strtrim.c ft_lstdel.c	ft_memset.c ft_strclr.c ft_strmapi.c ft_tolower.c ft_lstdelone.c ft_putchar.c ft_strcmp.c ft_strncat.c  ft_toupper.c ft_lstiter.c ft_putchar_fd.c ft_strcpy.c ft_strncmp.c ft_reverse.c ft_countw.c

OBJECT = ft_count_digit_u.o get_next_line.o ft_putllu.o ft_putlonglong.o ft_lowstr.o ft_itoa_base.o ft_reverse_bits.o ft_ispower.o ft_isvalid.o ft_atoi.o ft_lstmap.o	ft_putendl.o ft_strdel.o ft_strncpy.o ft_bzero.o ft_lstnew.o ft_putendl_fd.o ft_strdup.o ft_strnequ.o ft_isalnum.o ft_memalloc.o ft_putnbr.o ft_strequ.o ft_strnew.o ft_isalpha.o ft_memccpy.o ft_putnbr_fd.o ft_striter.o ft_strnstr.o ft_isascii.o ft_memchr.o ft_putstr.o ft_striteri.o ft_strrchr.o ft_isdigit.o ft_memcmp.o ft_putstr_fd.o	ft_strjoin.o ft_strsplit.o ft_isprint.o	ft_memcpy.o	ft_shwlst.o	ft_strlcat.o ft_strstr.o ft_itoa.o ft_memdel.o ft_strcat.o ft_strlen.o ft_strsub.o ft_lstadd.o ft_memmove.o	ft_strchr.o	ft_strmap.o	ft_strtrim.o ft_lstdel.o ft_memset.o ft_strclr.o ft_strmapi.o ft_tolower.o ft_lstdelone.o ft_putchar.o ft_strcmp.o ft_strncat.o	ft_toupper.o ft_lstiter.o ft_putchar_fd.o ft_strcpy.o ft_strncmp.o ft_reverse.o	ft_countw.o

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< 

clean:
	@rm -f $(OBJECT)
	@echo all clear

fclean: clean
	@rm -f $(NAME)
	@echo libft.a has been deleted

re: fclean all