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
{//оригинал сначала добавляет нули а потом ставит +
	//Исправить проверка на знак
	if (str[0] != '-' && place.type.flag)
		return (ft_stradd_front(str, ft_strlen(str) + 1, '+', place.type.flag));
	return (str);
}

char	*flags_space(char *str, t_placeholder place)
{
	if (str[0] != '-' && place.type.flag)
		return (ft_stradd_front(str, ft_strlen(str) + 1, ' ', place.type.flag));
	return (str);
}

char	*flags_zero(char *str, t_placeholder place)
{
	if (place.type.flag == 'd' || place.type.flag == 'i' || place.type.flag == 'o'
			|| place.type.flag == 'u' || place.type.flag == 'x' || place.type.flag == 'X')
		return (ft_stradd_front(str, place.width, '0', place.type.flag));
	else
		return (str);
}

char	*flags_hash(char *str, t_placeholder place)
{
	if (*str == '0')
		return (str);
	if (place.type.flag == 'o')
		return (ft_stradd_front(str, ft_strlen(str) + 1, '0', place.type.flag));
	else if (place.type.flag == 'x')
	{
		str = ft_stradd_front(str, ft_strlen(str) + 2, '0', place.type.flag);
		str[1] = 'x';
		return (str);
	}
	else if (place.type.flag == 'X')
	{
		str = ft_stradd_front(str, ft_strlen(str) + 2, '0', place.type.flag);
		str[1] = 'X';
		return (str);
	}
	return (str);
}
