/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:42 by debizhan          #+#    #+#             */
/*   Updated: 2023/05/29 16:27:01 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

int	ft_putunsign(unsigned int nbr, char *str)
{
	int	c;
	int	size;
	int	base;

	base = check_base(str);
	size = 1;
	if (nbr >= base)
		size += ft_putunsign(nbr / base, str);
	c = nbr % base;
	write(1, &str[c], 1);
	return (size);

}