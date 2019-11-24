# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anassif <anassif@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:52:25 by anassif           #+#    #+#              #
#    Updated: 2019/11/24 13:52:54 by anassif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c\
		ft_utils1.c\
		ft_utils2.c\
		ft_get_flags.c\
		ft_handle_flag_d.c\
		ft_handle_flag_u.c\
		ft_itoa.c\
		ft_handle_flag_x.c\
		ft_small_hexa.c\
		ft_big_hexa.c\
		ft_h_p.c\
		ft_pourcentage_p.c\
		ft_h_s.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
	@echo libftprintf.a was successfully made

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

bonus:
	gcc $(CFLAGS) -c $(SRC_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME) $(OBJ_BONUS)
re: fclean all