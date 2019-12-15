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

char	*check_flag(char *str, t_placeholder *place)
{
	if (*str == '-' && place->type.flag != 's' && place->type.flag != 'c' && place->flags != 0)
	{
		place->sign = 1;
		return (delete_sign(str));
	}
	return (str);
}

char			*to_str_logic(t_placeholder place, va_list ap)
{
	char *ans;

	ans = NULL;
	//type
	if (place.type.flag == '%')
		return (place.type.fun(ap));
	if (place.type.flag != 'm' && place.length.flag[0] == 'm')
		ans = check_flag(place.type.fun(ap), &place);
	else if (place.length.fun != NULL)
		ans = check_flag(place.length.fun(ap, place.type.flag), &place);
	//precision
	if (place.precision != 0) {
		if ((size_t)place.precision > ft_strlen(ans) && *ans != '\0')
			ans = ft_stradd_front(ans, place.precision, '0', place.type.flag);
		else if (place.type.flag == 's')
			ans = ft_strcut(ans, ft_strlen(ans) - place.precision);
	}
	//flags
	if (place.flags != 0)
		ans = get_flags(place, ans);
	//width
	if (place.width != 0 && (size_t)place.width > ft_strlen(ans)
			&& (place.flags & FLG_MINUS) == 0 && (place.flags & FLG_ZERO) == 0)
		ans = ft_stradd_front(ans, place.width, ' ', place.type.flag);
	if ((place.flags & FLG_PLUS) == 0 && (place.flags & FLG_SPACE) == 0)
		ans = get_sign(place, ans);
	return (ans);
}

int				print_this(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str)
		while (str[i] != '\0')
		{
			count += ft_putchar(str[i]);
			i++;
		}
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
		if (*format == '%')
		{
			format++;
			place = parse(ap, &format);
			if (place.type.flag == 'm')
				break ;
			ans = to_str_logic(place, ap);
			count += print_this(ans);
		}
	}
	va_end(ap);
	return (count);
}
