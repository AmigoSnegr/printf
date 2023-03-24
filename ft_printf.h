/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:07:27 by debizhan          #+#    #+#             */
/*   Updated: 2023/03/24 13:29:04 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *arg, ...);
int	ft_putstr_int(char *s);
int	ft_putnbr_int(int n);
int	ft_putchar_int(char c);
int	ft_puthex(long long n, char *str);

#endif