/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:17:28 by zbendahh          #+#    #+#             */
/*   Updated: 2022/11/18 20:22:40 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int		size;

	size = 0;
	if (format == 'c')
		size += ft_printchar(va_arg(args, int));
	else if (format == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		size += ft_printnbr(va_arg(args, int));
	else if (format == 'x')
		size += ft_print_hix(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		size += ft_print_hix(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
	{
		size += ft_printstr("0x");
		size += ft_print_hix(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (format == 'u')
		size += ft_printnbr_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		size += ft_printchar('%');
	else
		size = 1;
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				size += ft_formats(args, str[i]);
		}
		else
			size += ft_printchar(str[i]);
		if (str[i])
			i++;
	}
	va_end(args);
	return (size);
}
