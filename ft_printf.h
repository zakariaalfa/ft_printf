/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:29:28 by zbendahh          #+#    #+#             */
/*   Updated: 2022/11/18 19:32:55 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

int	ft_formats(va_list args, const char format);
int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printnbr(int n);
int	ft_printnbr_unsigned(unsigned int n);
int	ft_print_hix(unsigned long num, char *base);
#endif