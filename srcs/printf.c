/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:33 by snorcros          #+#    #+#             */
/*   Updated: 2019/11/07 10:43:50 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_placeholder	parse(va_list ap, const char **format)
{
	t_placeholder place;

	place = new_placeholder();
	if (set_type(&place, *format))
	{
		*format += 1;
		return (place);
	}
	*format += set_flags(&place, *format);
	*format += set_width(&place, *format, ap);
	*format += set_precision(&place, *format);
	*format += set_length(&place, *format);
	*format += set_type(&place, *format);
	return place;
}

char			*to_str_logic(t_placeholder place, va_list ap)
{
	char *ans;

	ans = NULL;
	//1
	if (place.type.flag != 'm' && place.length.flag[0] == 'm')
		ans = place.type.fun(ap);
	else if (place.length.fun != NULL)
		ans = place.length.fun(ap, place.type.flag);
	//2
	if (place.flags != 0)
		ans = get_flags(place, ans);
	//3
	if (place.width != 0 && (size_t)place.width > ft_strlen(ans)
			&& (place.flags & FLG_MINUS) == 0)
			ans = ft_stradd_front(ans, place.width, ' ', place.type.flag);
	return (ans);
}

int				print_this(t_placeholder place, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	if (place.type.flag != 's' || (ft_strcmp((const char *)str, "(null)") == 0))
		free(str);
	return (count);
}

int				ft_printf(const char *format, ...)
{
	int				count;
	va_list			ap;
	t_placeholder	place;
	char			*ans;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			count += ft_putchar(*format);
			format++;
		}
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			place = parse(ap, &format);
			if (place.type.flag == 'm')
				break ;
			ans = to_str_logic(place, ap);
			count += print_this(place, ans);
		}
		else if (*format == '%' && (*(format + 1) == '%' || *(format + 1) == '\0'))
		{
			count += ft_putchar(*format);
			format += 2;
		}
	}
	va_end(ap);
	return (count);
}
