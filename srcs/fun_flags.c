/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:36:05 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/01 19:50:14 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*flags_minus(char *str, t_placeholder place)
{
	if (*str == '\0' && place.type.flag == 'c')
		return (str);
	return (ft_stradd_back(str, place.width, ' ', place.type.flag));
}

char	*flags_plus(char *str, t_placeholder place)
{
	if (place.type.flag == '%' || place.type.flag == 'u')
		return (str);
	if (place.sign == 0)
		return (ft_stradd_front(str, ft_strlen(str) + 1,
														'+', place.type.flag));
	else
		return (ft_stradd_front(str, ft_strlen(str) + 1,
														'-', place.type.flag));
}

char	*flags_space(char *str, t_placeholder place)
{
	if (place.type.flag == '%' || place.type.flag == 'u')
		return (str);
	if (place.sign == 0)
		return (ft_stradd_front(str, ft_strlen(str) + 1,
														' ', place.type.flag));
	else
		return (ft_stradd_front(str, ft_strlen(str) + 1,
														'-', place.type.flag));
}

char	*flags_zero(char *str, t_placeholder place)
{
	if (place.type.flag == 'd' || place.type.flag == 'i'
			|| place.type.flag == 'o' || place.type.flag == '%'
			|| place.type.flag == 'u' || place.type.flag == 'x'
			|| place.type.flag == 'X')
	{
		if (place.width == 0)
			return (str);
		if (place.precision != -1)//kostil
			return (ft_stradd_front(str, place.precision,
														'0', place.type.flag));
		else if (place.sign == 0 && (place.flags & FLG_SPACE) == 0
									&& (place.flags & FLG_PLUS) == 0)
			return (ft_stradd_front(str, place.width,
														'0', place.type.flag));
		else
			return (ft_stradd_front(str, place.width - 1,
														'0', place.type.flag));
	}
	else
		return (str);
}

int		only_zero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
int		only_zero_and_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' || str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*flags_hash(char *str, t_placeholder place)
{
	if (*str == '0' && *(str + 1) == '\0' && place.width < 1
													&& place.precision == -1)
		return (str);
	if (place.type.flag == 'o')
	{
		if ((place.flags & FLG_ZERO) == FLG_ZERO
			&& ((place.width <= (int)ft_strlen(str) && str[0] != '0'
										&& place.width >= place.precision)
				|| (str[0] != '0' && place.width > (int)ft_strlen(str))))
			return (ft_stradd_front(str, ft_strlen(str) + 1,
														'0', place.type.flag));
		if ((place.precision > place.width && place.width != 0)
				|| (place.flags & FLG_ZERO) == FLG_ZERO
				|| (place.precision == (int)ft_strlen(str) && str[0] == '0')
				|| (only_zero_and_space(str) && place.precision == -1))
			return (str);
		if (only_zero(str) && place.precision != -1)
			return (ft_stradd_front(str, place.precision,
														'0', place.type.flag));
		else
			return (ft_stradd_front(str, ft_strlen(str) + 1,
														'0', place.type.flag));
	}
	else if (place.type.flag == 'x' && !only_zero(str))
	{
		if ((place.flags & FLG_ZERO) == 0 || str[0] != '0'
		|| place.precision > place.width || place.width > (int)ft_strlen(str))
			str = ft_stradd_front(str, ft_strlen(str) + 2,
														'0', place.type.flag);
		str[1] = 'x';
	}
	else if (place.type.flag == 'X' && !only_zero(str))
	{
		if ((place.flags & FLG_ZERO) == 0 || str[0] != '0'
		|| place.precision > place.width || place.width > (int)ft_strlen(str))
			str = ft_stradd_front(str, ft_strlen(str) + 2,
														'0', place.type.flag);
		str[1] = 'X';
	}
	return (str);
}
