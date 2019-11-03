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
	if (!place == (t_placeholder)NULL)
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

char	*to_str_logic(t_placeholder place, va_list ap)
{
	char *ans;

	if (place.type.flag != NULL)
	{
		ans = place.type.fun(ap);
	}
	return (ans);
}


int		print_this(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	free(str);
	return (count);
}

char *ft_c(va_list ap)
{
	char *ans;

	if (!(ans = ft_strnew(2))
		return (NULL);
	ans[0] = va_arg(ap, char);
	ans[1] = '\0';
	return (ans);
}

int		ft_printf(const char * format, ...)
{
	int		count;
	va_list	ap;
	int		i;
	t_placeholder place;
	char *ans;

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
			place = parse(ap, format);
			ans = to_str_logic(place, ap);
			count += print_this(ans);

		}
	}
	va_end(ap);
	return (count);
}

