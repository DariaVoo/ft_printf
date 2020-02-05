/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:31:29 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 15:31:31 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			if (*format == '\0')
				return (0);
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
