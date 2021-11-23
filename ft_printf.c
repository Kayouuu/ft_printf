/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:21:26 by psaulnie          #+#    #+#             */
/*   Updated: 2021/11/15 17:27:54 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_special(const char *format, va_list args, int counter)
{
	int	length;

	length = 0;
	if (format[counter + 1] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (format[counter + 1] == 'c')
		length = ft_putchar(va_arg(args, int));
	else if (format[counter + 1] == 's')
		length = ft_putstr(va_arg(args, char *));
	else if (format[counter + 1] == 'd' || format[counter + 1] == 'i')
		length = ft_putnbr((long)va_arg(args, int));
	else if (format[counter + 1] == 'u')
		length = ft_putunsigned(va_arg(args, unsigned int));
	else if (format[counter + 1] == 'p')
		length = ft_putpnt(va_arg(args, uint64_t), "0123456789abcdef");
	else if (format[counter + 1] == 'x')
		length = ft_puthexa(va_arg(args, uint32_t), "0123456789abcdef");
	else if (format[counter + 1] == 'X')
		length = ft_puthexa(va_arg(args, uint32_t), "0123456789ABCDEF");
	return (length);
}

int	print(const char *format, va_list args)
{
	int	counter;
	int	length;

	counter = 0;
	length = 0;
	while (format[counter])
	{
		if (format[counter] == '%' && format[counter + 1])
			length += print_special(format, args, counter++);
		else
		{
			ft_putchar(format[counter]);
			length++;
		}
		counter++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		string_len;

	va_start(args, format);
	string_len = print(format, args);
	va_end(args);
	return (string_len);
}
