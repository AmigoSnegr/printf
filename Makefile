# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 14:06:02 by debizhan          #+#    #+#              #
#    Updated: 2023/05/29 15:53:33 by debizhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c ft_putchar_int.c ft_putnbr_int.c ft_putnbr_base.c ft_putstr_int.c ft_strlen.c ft_putunsign.c ft_putaddress.c
OBJ		=	$(SRC:.c=.o)
RM		=	rm -f
NAME	=	libftprintf.a



all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@mv libft/libft.a .
			@ar rcs	$(NAME) $(OBJ) libft.a
clean: 
			@$(RM)	$(OBJ)
fclean:		clean
			@$(RM)	$(NAME)
			@$(RM)	libft.a
			@make fclean -C libft		
re: 		fclean all
