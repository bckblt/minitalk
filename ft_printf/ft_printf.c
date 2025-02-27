/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:32:13 by bakarabu          #+#    #+#             */
/*   Updated: 2024/11/07 18:32:13 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else
		i += write(1, "(null)", 6);
	return (i);
}

int	putbase(unsigned long nbr, char *base, int type, int len)
{
	int	written;

	written = 0;
	if (type == 1 && nbr == 0)
		return (write(1, "(nil)", 5));
	if (type == 1)
		written += write(1, "0x", 2);
	if ((int)nbr < 0 && type == 0)
	{
		written += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr / len != 0)
		written += putbase(nbr / len, base, 2, len);
	written += write(1, &base[nbr % len], 1);
	return (written);
}

int	ft_chr(char c, va_list a)
{
	int	x;

	x = 0;
	if (c == 'c')
	{
		x = va_arg(a, int);
		return (write(1, &x, 1));
	}
	else if (c == 's')
		return (ft_putstr(va_arg(a, const char *)));
	else if (c == 'd' || c == 'i')
		return (putbase(va_arg(a, int), "0123456789", 0, 10));
	else if (c == 'p')
		return (putbase(va_arg(a, unsigned long), "0123456789abcdef", 1, 16));
	else if (c == 'x')
		return (putbase(va_arg(a, unsigned int), "0123456789abcdef", 2, 16));
	else if (c == 'X')
		return (putbase(va_arg(a, unsigned int), "0123456789ABCDEF", 2, 16));
	else if (c == 'u')
		return (putbase(va_arg(a, unsigned int), "0123456789", 2, 10));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	a;

	len = 0;
	i = 0;
	va_start(a, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			len += write(1, "%", 1);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] != '\0' && str[i + 1] != '%')
		{
			len += ft_chr(str[i + 1], a);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(a);
	return (len);
}
