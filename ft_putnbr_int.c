/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:19:52 by dbizjano          #+#    #+#             */
/*   Updated: 2023/03/24 13:27:51 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_int(int n)
{
	long	nbr;
	char	c;
	int		size;

	nbr = n;
	size = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		size += 1;
	}
	if (nbr > 9)
		size += ft_putnbr_int(nbr / 10);
	c = nbr % 10 + 48;
	write(1, &c, 1);
	return (size);
}
