/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:41:37 by debizhan          #+#    #+#             */
/*   Updated: 2023/05/17 16:25:37 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "libft/ft_strncmp.c"
static int	check_base(char *str)
{
	if (ft_strncmp(str, "0123456789", ft_strlen(str)) == 0)
		return (10);
	else if (ft_strncmp(str, "0123456789abcdef", ft_strlen(str)) == 0
		|| ft_strncmp(str, "0123456789ABCDEF", ft_strlen(str)) == 0)
		return (16);
	return (0);
}

int	ft_putnbr_base(long long nbr, char *str)
{
	int	c;
	int	size;
	int	base;
	unsigned int unbr;

	base = check_base(str);
	size = 1;
	if (nbr < 0 && base == 10)
	{
		nbr = -nbr;
		size += 1;
		write(1, "-", 1);
	}
	if (nbr >= base)
		size += ft_putnbr_base(nbr / base, str);
	c = nbr % base;
	write(1, &str[c], 1);
	return (size);
}
