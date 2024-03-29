/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:07:27 by debizhan          #+#    #+#             */
/*   Updated: 2023/05/29 16:28:12 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdint.h>

int	ft_printf(const char *arg, ...);
int	ft_putstr_int(char *s);
int	ft_putnbr_int(int n);
int	ft_putchar_int(char c);
int	ft_putnbr_base(long long n, char *str);
int	ft_putunsign(unsigned int nbr, char *str);
int	ft_putaddress(size_t nbr, char *str);

#endif