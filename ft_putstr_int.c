/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:30:25 by dbizjano          #+#    #+#             */
/*   Updated: 2023/03/24 13:28:20 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int	ft_putstr_int(char *s)
{
	int	size;

	size = ft_strlen(s);
	if (!s)
	{
		write(1, "(null)", 6);
		return (0);
	}
	write(1, s, size);
	return (size);
}
