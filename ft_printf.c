/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:50:58 by debizhan          #+#    #+#             */
/*   Updated: 2023/03/24 13:31:41 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	check_flag(char flag, va_list lst, int *i, int *size)
{
	if (flag == 'c')
	{
		*size += ft_putchar_int(va_arg(lst, int));
		*i += 2;
	}
	else if (flag == 'p')
	{
		write(1, "0x", 2);
		*size += 2 + ft_putnbr_base(va_arg(lst, size_t), "0123456789abcdef");
		*i += 2;
	}
	else if (flag == 'd')
	{
		// *size += ft_putnbr_int(va_arg(lst, int));
		*size += ft_putnbr_base(va_arg(lst, int), "0123456789");
		*i += 2;
	}
	else if (flag == 's')
	{
		*size += ft_putstr_int(va_arg(lst, char *));
		*i += 2;
	}
}

int	ft_printf(const char *arg, ...)
{
	va_list	lst;
	int		i;
	int		size;

	size = 0;
	i = 0;
	va_start(lst, arg);
	while (arg[i] != 0)
	{
		if (arg[i] == '%')
		{
			check_flag(arg[i + 1], lst, &i, &size);
		}
		else
		{
			ft_putchar_int(arg[i]);
			i++;
			size++;
		}
	}
	va_end(lst);
	return (size);
}

int	main(void)
{
	char	*ptr = "something";
	
	int size = ft_printf("Testing\nnumber = %d\nstring %s\nchar = %c\npointer = %p\n", INT_MIN, "apple", 'c', ptr);
	ft_printf("size = %d\n", size);
	return (0);
}
