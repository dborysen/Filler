#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 16:40:13 by dborysen          #+#    #+#              #
#    Updated: 2018/01/11 16:40:16 by dborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = dborysen.filler

FT_PRINTF = ft_printf

SRCS =  filler.c pos_coord.c save_maps.c search_params.c

OBJECT = filler.o pos_coord.o save_maps.o search_params.o

INCLUDES = ft_printf/ft_printf.h 

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(FT_PRINTF)
	@gcc -Wall -Wextra -Werror -I filler.h $(SRCS) ft_printf/libftprintf.a -o ./$(NAME)


%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) filler.h -c $< 

comp:
	@gcc $(FLAGS) -I filler.h $(SRCS) ft_printf/libftprintf.a -o ./$(NAME)

comp1:
	@gcc $(FLAGS) -I filler.h $(SRCS) ft_printf/libftprintf.a -o resources/players/$(NAME)
	
comp_b:
	 gcc $(FLAGS) -I filler.h bonus.c  ft_printf/libftprintf.a -o resources/bonus

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

clean:
	@rm -f $(OBJECT)
	@make clean -C $(FT_PRINTF)

fclean: clean
	@rm -f $(NAME)
	@rm filler.h.gch
	@make fclean -C $(FT_PRINTF)

re: fclean all