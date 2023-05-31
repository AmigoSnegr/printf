/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:50:58 by debizhan          #+#    #+#             */
/*   Updated: 2023/05/29 16:27:55 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	check_flag(char flag, va_list lst)
{
	void	*ptr;

	if (flag == 'c')
		return (ft_putchar_int(va_arg(lst, int)));
	else if (flag == 'p')
	{
		ptr = va_arg(lst, void *);
		write(1, "0x", 2);
		return (2 + ft_putaddress((size_t) ptr, "0123456789abcdef"));
	}
	else if (flag == 'u')
		return (ft_putunsign(va_arg(lst, int), "0123456789"));
	else if (flag == 'd' || flag == 'i' || flag == 'u')
		return (ft_putnbr_base(va_arg(lst, int), "0123456789"));
	else if (flag == 'x')
		return (ft_putunsign(va_arg(lst, int), "0123456789abcdef"));
	else if (flag == 'X')
		return (ft_putunsign(va_arg(lst, int), "0123456789ABCDEF"));
	else if (flag == 's')
		return (ft_putstr_int(va_arg(lst, char *)));
	else if (flag == '%')
		return (ft_putchar_int('%'));
	return (0);
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
			size += check_flag(arg[i + 1], lst);
			i += 2;
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
// #include <limits.h>
// int	main(void)
// {
// 	char	*ptr = "something";
// 	ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	// printf("%u\n", -2134);
// 	// int size = ft_printf("Testing\nnumber = %d\nstring %s\nchar = %c\npointer = %p\nhex = %x\ncap hex = %X\n", INT_MIN, "apple", 'c', ptr, 100, 24244224);
// 	// ft_printf("size = %d\n-------------\n", size);
// 	// int og_size = printf("Testing\nnumber = %d\nstring %s\nchar = %c\npointer = %p\nhex = %x\ncap hex = %X\n", INT_MIN, "apple", 'c', ptr, 100, 24244224);
// 	// ft_printf("og_size = %d\n", og_size);
// 	return (0);
// }
