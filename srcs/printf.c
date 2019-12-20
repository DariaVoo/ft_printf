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
	*format += set_precision(&place, *format, ap);
	*format += set_length(&place, *format);
	*format += set_type(&place, *format);
	return place;
}

char	*check_flag(char *str, t_placeholder *place)
{
	if (*str == '\0' && place->type.flag == 'c')
		place->flags &= FLG_NULL;
	else if (*str == '-' && place->type.flag != 's'
		&& place->type.flag != 'c' && (place->flags != 0 || place->precision != -1))
	{
		place->sign = 1;
		return (delete_sign(str));
	}
	return (str);
}

size_t	strcount_digit(char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '.' && str[count] != '\0')
		count++;
	return (count);
}

char *get_precision_float(t_placeholder *place, char *ans)
{
	size_t len;

	len = ft_strlen(ans);
	if (place->precision == 0)
		return (ft_strcut(ans, strcount_digit(ans)));
	else if (place->precision > len)
		return (ft_stradd_back(ans, place->precision, '0', place->type.flag));
	else
		return (ft_strcut(ans, ft_strlen(ans) - place->precision));
	return (ans);
}

char *get_precision(t_placeholder *place, char *ans)
{
	if (place->type.flag == 'c' || (place->type.flag == 'o' &&
	(place->flags & FLG_HASH) != 0 && *ans == '0'))
		return (ans);
	if (place->type.flag == 'f')
		return (get_precision_float(place, ans));
	else if (place->precision == 0 && *ans == '0')
	{
		free(ans);
		place->flags &= FLG_NULL;
		return (ft_strnew(1));
	}
	else if ((place->type.flag == 'd' || place->type.flag == 'i' || place->type.flag == 'o'
		|| place->type.flag == 'u' || place->type.flag == 'x' || place->type.flag == 'X')
		&& (place->precision > 0 && (size_t)place->precision > ft_strlen(ans) && *ans != '\0'))
	{
		place->flags &= ~FLG_ZERO;
		ans = ft_stradd_front(ans, place->precision, '0', place->type.flag);
	}
	else if (place->type.flag == 's' && place->precision >= 0)
		ans = ft_strcut(ans, ft_strlen(ans) - place->precision);
	return (ans);
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
	if (place.precision != -1)
		ans = get_precision(&place, ans);
	//flags
	ans = get_flags(place, ans);
	//width
	if (ft_strlen(ans) == 0 && place.width != 0 && place.type.flag == 'c')
		ans = ft_stradd_front(ans, place.width - 1, ' ', place.type.flag);
	else if (place.width != 0 && (size_t)place.width > ft_strlen(ans)
		&& (place.flags & FLG_MINUS) == 0 && (place.flags & FLG_ZERO) == 0)
		ans = ft_stradd_front(ans, place.width, ' ', place.type.flag);
	if ((place.flags & FLG_PLUS) == 0 && (place.flags & FLG_SPACE) == 0)
		ans = get_sign(place, ans);
	return (ans);
}

int				print_this(t_placeholder place, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	if (place.type.flag == 'c' && str[i] == '\0' &&
		((i < place.width && place.width != 0) || *str == '\0'))
		count += write(1, "\0", 1);
	free(str);
	return (count);
}

/*int				print_ban(const char *format)
{
	int	i;

	i = 0;
	if (!format || *format == '\0')
		return (-1);
	while (format[i] != '\0')
	{
		write(1, &format[i], 1);
		i++;
	}
	return (i);
}*/

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
			{
				//return (print_ban(format));
				return (-1);
			}
			ans = to_str_logic(place, ap);
			count += print_this(place, ans);
		}
	}
	va_end(ap);
	return (count);
}
