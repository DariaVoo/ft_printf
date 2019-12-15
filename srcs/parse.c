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

char	*get_sign(t_placeholder placeholder, char *str)
{
	if (placeholder.sign != 0 && placeholder.width == 0)
		return (ft_stradd_front(str, ft_strlen(str) + 1, '-', placeholder.type.flag));
	else if (placeholder.sign != 0 && placeholder.width != 0)
		return (ft_strcat_front(str, "-", placeholder.width - 1, 1));
	else
		return (str);
}

int	set_flags(t_placeholder *placeholder, const char *format)
{
	size_t i;
	int		count_flags;

	i = 0;
	count_flags = 0;
	while (flags[i].flag != 'm') {
		if (flags[i].flag == *format) {
			placeholder->flags |= flags[i].inint;
			format++;
			i = 0;
			count_flags++;
			continue ;
		}
		i++;
	}
	if ((placeholder->flags & FLG_MINUS) == FLG_MINUS)
		placeholder->flags &= ~FLG_ZERO;
	if ((placeholder->flags & FLG_PLUS) == FLG_PLUS)
		placeholder->flags &= ~FLG_SPACE;
	return (count_flags);
}

char	*get_flags(t_placeholder placeholder, char *str)
{
	size_t	i;

	i = 0;
	while (flags[i].flag != 'm')
	{
		if ((placeholder.flags & flags[i].inint) == flags[i].inint)
			str = flags[i].fun(str, placeholder);
		i++;
	}
	return (str);
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
		if ((p = ft_atoi(format)) >= 0)
		{
			placeholder->precision = p;
			if (p == 0)
				k++;
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
		else if (*format == lengths[i].flag[0] && i > 1)
		{
			placeholder->length.flag = lengths[i].flag;
			placeholder->length.fun = lengths[i].fun;
			return (1);
		}
		i++;
	}
	return (0);
}
