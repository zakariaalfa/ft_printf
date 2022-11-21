/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:31:24 by zbendahh          #+#    #+#             */
/*   Updated: 2022/11/18 20:18:03 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		count += write (1, "(null)", 6);
		return (count);
	}
	else
	{
		while (s[i])
		{
			count += ft_printchar(s[i]);
			i++;
		}
		return (count);
	}
}

int	ft_printnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_printchar('-');
		count += ft_printnbr(214748364);
		count += ft_printnbr(8);
	}
	else if (n < 0)
	{
		count += ft_printchar('-');
		count += ft_printnbr(-n);
	}
	else if (n >= 10)
	{
		count += ft_printnbr(n / 10);
		count += ft_printchar(n % 10 + '0');
	}
	else
		count += ft_printchar(n + '0');
	return (count);
}

int	ft_printnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_printnbr(n / 10);
		count += ft_printchar(n % 10 + '0');
	}
	else
		count += ft_printchar(n + '0');
	return (count);
}

int	ft_print_hix(unsigned long num, char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_print_hix(num / 16, base);
		count += ft_print_hix(num % 16, base);
	}
	else
		count += ft_printchar(base[num]);
	return (count);
}
