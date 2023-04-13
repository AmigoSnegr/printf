# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: debizhan <debizhan@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 14:06:02 by debizhan          #+#    #+#              #
#    Updated: 2023/04/13 14:14:34 by debizhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c ft_putchar_int.c ft_putnbr_int.c ft_putnbr_base.c ft_putstr_int.c ft_strlen.c
OBJ		=	$(SRC:.c=.o)
RM		=	rm -f
NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs	$(NAME) $(OBJ)
clean: 
			$(RM)	$(OBJ)
fclean:		clean
			$(RM)	$(NAME)			
re: 		fclean all
