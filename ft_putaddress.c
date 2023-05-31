/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:50:16 by debizhan          #+#    #+#             */
/*   Updated: 2023/05/29 16:27:36 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *str)
{
	if (ft_strncmp(str, "0123456789", ft_strlen(str)) == 0)
		return (10);
	else if (ft_strncmp(str, "0123456789abcdef", ft_strlen(str)) == 0
		|| ft_strncmp(str, "0123456789ABCDEF", ft_strlen(str)) == 0)
		return (16);
	return (0);
}

int	ft_putaddress(size_t nbr, char *str)
{
	int	c;
	int	size;
	int	base;

	base = check_base(str);
	size = 1;
	if (nbr >= base)
		size += ft_putaddress(nbr / base, str);
	c = nbr % base;
	write(1, &str[c], 1);
	return (size);
}