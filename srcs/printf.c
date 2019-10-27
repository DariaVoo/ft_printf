/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:33 by snorcros          #+#    #+#             */
/*   Updated: 2019/10/27 14:48:20 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int		ft_printf(const char * restrict format, ...)
{
	int		count;
	va_list	ap;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format)
	{
		while (*format != '%' && format)
		{
			count += ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
			while (i < 2)
			{
				if (*format == flfun[i].flag)
					count += flfun[i].fun(va_arg(ap, char *));
				i++;
			}
		}
	}
	va_end(ap);
	return (count);
}
