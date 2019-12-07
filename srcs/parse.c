/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:36:35 by snorcros          #+#    #+#             */
/*   Updated: 2019/12/07 14:36:37 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "funfortypes.h"

int	set_type(t_placeholder *placeholder, const char *format)
{
	size_t i;

	i = 0;
	while (types[i].flag != 'm')
	{
		if (*format == types[i].flag)
		{
			placeholder->type = types[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	set_flags(t_placeholder *placeholder, const char *format)
{
	size_t i;

	i = 0;
	while (flags[i].flag != 'm')
	{
		if (flags[i].flag == *format)
		{
			placeholder->flags.flag = flags[i].flag;
			placeholder->flags.fun = flags[i].fun;
			return (1);
		}
		i++;
	}
	return (0);
}

int	set_width(t_placeholder *placeholder, const char *format, va_list ap)
{
	int w;
	int k;

	if (*format == '*')
	{
		if (*(format + 1) != '.')
			placeholder->width = va_arg(ap, int);
		else
			placeholder->precision = va_arg(ap, int);
		return (1);
	}
	if ((w = ft_atoi(format)) > 0)
	{
		k = 0;
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

int	set_precision(t_placeholder *placeholder, const char *format)
{
	int p;
	int k;

	k = 0;
	if (*format == '.')
	{
		k++;
		format++;
		if ((p = ft_atoi(format)) > 0)
		{
			placeholder->precision = p;
			while (p > 0)
			{
				p /= 10;
				k++;
			}
			return (k);
		}
	}
	return (0);
}

int	set_length(t_placeholder *placeholder, const char *format)
{
	size_t i;

	i = 0;
	while (lengths[i].flag[0] != 'm')
	{
		if (*format == lengths[i].flag[0] &&
			*(format + 1) == lengths[i].flag[1])
		{
			placeholder->length.flag = lengths[i].flag;
			placeholder->length.fun = lengths[i].fun;
			return (2);
		}
		else if (*format == lengths[i].flag[0])
		{
			placeholder->length.flag = lengths[i].flag;
			placeholder->length.fun = lengths[i].fun;
			return (1);
		}
		i++;
	}
	return (0);
}
