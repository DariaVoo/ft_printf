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

t_placeholder	check_place(t_placeholder *place, const char **format, int shamt)
{
	int	count;

	if (placeholder_isnotempty(*place) && *(*format + shamt) != '\0')
	{
		count = shamt;
		//count += write(1, "%", 1);
		*format += count;
		while (*(*format) != '\0') // && *(*format) != '%')
		{
			count += ft_putchar(*(char *)*format);
			*format += 1;
		}
		place->width = count;
		place->length.flag = "non";
	}
	else
		*format += shamt;
	return (*place);
}

t_placeholder	parse(va_list ap, const char **format)
{
	t_placeholder	place;
	size_t 			shamt;

	shamt = 0;
	place = new_placeholder();
	if (set_type(&place, *format))
	{
		*format += 1;
		return (place);
	}
	shamt += set_flags(&place, *format);
	shamt += set_width(&place, *format + shamt, ap);
	shamt += set_precision(&place, *format + shamt, ap);
	shamt += set_length(&place, *format + shamt);
	shamt += set_type(&place, *format + shamt);
	*format += shamt;
	return (place);
	//return check_place(&place, format, shamt);
}

char			*check_flag(char *str, t_placeholder *place)
{
	if (place->type.flag == 'c')
		place->flags &= ~FLG_ZERO;
	if (*str == '\0' && place->type.flag == 'c')
		place->flags &= FLG_NULL;
	else if (place->type.flag == 'f' && (*str == 'n' || *str == 'i'
			|| *(str + 1) == 'i' || *(str + 1) == 'n'))
	{
		place->flags &= FLG_NULL;
		place->precision = 0;
	}
	else if (*str == '-' && place->type.flag != 's' && place->type.flag != 'f'
		&& place->type.flag != 'c' && (place->flags != 0 || place->precision != -1))
	{
		place->sign = 1;
		return (delete_sign(str));
	}
	return (str);
}

char	*get_width(t_placeholder place, char *ans)
{
	//set sign
	if ((place.flags & FLG_PLUS) == 0 && (place.flags & FLG_SPACE) == 0)
		ans = get_sign(place, ans);
	//set width
	if (place.width != 0)
	{
		if (ft_strlen(ans) == 0  && place.type.flag == 'c')
			ans = ft_stradd_front(ans, place.width - 1, ' ', place.type.flag);
		else if ((size_t) place.width > ft_strlen(ans)
				 && (place.flags & FLG_MINUS) == 0 && ((place.flags & FLG_ZERO) == 0 || place.type.flag == 's'))
			ans = ft_stradd_front(ans, place.width, ' ', place.type.flag);
	}
	return (ans);
}

char			*to_str_logic(t_placeholder place, va_list ap)
{
	char *ans;

	ans = NULL;
	//type
	if (place.type.flag != 'm' && place.length.flag[0] == 'm')
		ans = check_flag(place.type.fun(ap), &place);
	else if (place.length.fun != NULL)
		ans = check_flag(place.length.fun(ap, place.type.flag), &place);
	//precision
	if (place.precision != -1)
		ans = get_precision(&place, ans);
	//flags
	ans = get_flags(place, ans);//here
	//width and set sign
	ans = get_width(place, ans);
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
			if (ft_strcmp(place.length.flag, "non") == 0)
				return (place.width);
			else if (placeholder_isempty(place) || (place.type.flag == 'm' && place.length.flag[0] != 'm'))
				return (-1);
			else if (place.type.flag == 'm')
				break ;
			ans = to_str_logic(place, ap);
			count += print_this(place, ans);
		}
	}
	va_end(ap);
	return (count);
}
