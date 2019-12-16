/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:36:05 by snorcros          #+#    #+#             */
/*   Updated: 2019/12/07 14:36:08 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char 	*flags_minus(char *str, t_placeholder place)
{
	return (ft_stradd_back(str, place.width, ' ', place.type.flag));
}

char	*flags_plus(char *str, t_placeholder place)
{
	if (place.type.flag == '%' || place.type.flag == 'u')
		return (str);
	if (place.sign == 0)
		return (ft_stradd_front(str, ft_strlen(str) + 1, '+', place.type.flag));
	else
		return (ft_stradd_front(str, ft_strlen(str) + 1, '-', place.type.flag));
}

char	*flags_space(char *str, t_placeholder place)
{
	if (place.type.flag == '%' || place.type.flag == 'u')
		return (str);
	if (place.sign == 0)
		return (ft_stradd_front(str, ft_strlen(str) + 1, ' ', place.type.flag));
	else
		return (ft_stradd_front(str, ft_strlen(str) + 1, '-', place.type.flag));
}

char	*flags_zero(char *str, t_placeholder place)
{
	if (place.type.flag == 'd' || place.type.flag == 'i' || place.type.flag == 'o'
			|| place.type.flag == 'u' || place.type.flag == 'x' || place.type.flag == 'X')
	{
		if (place.width == 0)
			return (str);
		if (place.sign == 0 && (place.flags & FLG_SPACE) == 0 && (place.flags & FLG_PLUS) == 0)
			return (ft_stradd_front(str, place.width, '0', place.type.flag));
		else
			return (ft_stradd_front(str, place.width - 1, '0', place.type.flag));
	}
	else
		return (str);
}

char	*flags_hash(char *str, t_placeholder place)
{
	if (*str == '0' && *(str + 1) == '\0')
		return (str);
	if (place.type.flag == 'o')
		if (place.precision > place.width)
			return (str);
		else if (place.width == 0)
			return (ft_stradd_front(str, ft_strlen(str) + 1, '0', place.type.flag));
		else
			return (ft_strcat_front(str, "0", place.width - 1, 1));
	else if (place.type.flag == 'x')
	{
		if (place.width != 0 && (place.flags & FLG_MINUS) != 0)
			str = ft_strcat_front(str, "0x", place.width - 1, 2);
		else if ((place.flags & FLG_ZERO) == 0)
			str = ft_stradd_front(str, ft_strlen(str) + 2, '0', place.type.flag);
		str[1] = 'x';
	}
	else if (place.type.flag == 'X')
	{
		if (place.width != 0)
			str = ft_strcat_front(str, "0X", place.width - 1, 2);
		else if ((place.flags & FLG_ZERO) == 0)
			str = ft_stradd_front(str, ft_strlen(str) + 2, '0', place.type.flag);
		str[1] = 'X';
	}
	return (str);
}
