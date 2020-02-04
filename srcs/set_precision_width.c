/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 21:13:28 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 21:13:30 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	set_precision(t_placeholder *placeholder, const char *format, va_list ap)
{
	int p;
	int k;

	k = 0;
	if (*format == '.')
	{
		k++;
		format++;
		if (*format == '*')
			k += star_precision(placeholder, ap);
		else if ((p = ft_atoi(format)) >= 0)
		{
			placeholder->precision = p;
			while (p > 0)
			{
				p /= 10;
				k++;
			}
			if (p == 0 && *format == '0')
				k++;
		}
		return (k);
	}
	return (0);
}

int	set_width(t_placeholder *placeholder, const char *format, va_list ap)
{
	int w;
	int k;

	k = 0;
	if (*format == '*')
	{
		if (star_width(placeholder, format, ap))
			return (1);
		k += 1;
		format++;
	}
	if ((w = ft_atoi(format)) > 0)
	{
		placeholder->width = w;
		while (w > 0)
		{
			w /= 10;
			k++;
		}
		return (k);
	}
	return (0);
}
