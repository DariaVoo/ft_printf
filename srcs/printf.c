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

t_placeholder parse(va_list ap, char *format)
{
	t_placeholder place;

	place = new_placeholder();
	if (place == (t_placeholder)NULL)
		return ((t_placeholder)NULL);
	if (set_type(&place, format))
	{
		format++;
		return (place);
	}
	set_flags(&place, format);
	set_width(&place, format, ap);
	set_precision(&place, format);
	set_length(&place, format);
	set_type(&place, format);
	return place;
}

int		print_this(t_placeholder place, char *str, size_t strlen)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < strlen)
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}



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
			//parse
			while (i < 2)
			{
				//if (*format == flfun[i].flag)
					count += flfun[i].fun(va_arg(ap, char *));
				i++;
			}
		}
	}
	va_end(ap);
	return (count);
}
