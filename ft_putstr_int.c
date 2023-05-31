/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:30:25 by dbizjano          #+#    #+#             */
/*   Updated: 2023/05/19 16:20:51 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int	ft_putstr_int(char *s)
{
	int	size;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	size = ft_strlen(s);
	write(1, s, size);
	return (size);
}
