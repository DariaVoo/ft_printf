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

char	*flags_plus(char *str, char type)
{
	if (str[0] != '-' && type)
		return (ft_stradd_front(str, ft_strlen(str) + 1, '+', type));
	return (str);
}

char	*flags_space(char *str, char type)
{
	if (str[0] != '-' && type)
		return (ft_stradd_front(str, ft_strlen(str) + 1, ' ', type));
	return (str);
}

char	*flags_zero(char *str, char type)
{
	if (type == 'd' || type == 'i' || type == 'o'
			|| type == 'u' || type == 'x' || type == 'X')
		return (ft_strreplace(str, ' ', '0'));
	else
		return (str);
}

char	*flags_hash(char *str, char type)
{
	if (*str == '0')
		return (str);
	if (type == 'o')
		return (ft_stradd_front(str, ft_strlen(str) + 1, '0', type));
	else if (type == 'x')
	{
		str = ft_stradd_front(str, ft_strlen(str) + 2, '0', type);
		str[1] = 'x';
		return (str);
	}
	else if (type == 'X')
	{
		str = ft_stradd_front(str, ft_strlen(str) + 2, '0', type);
		str[1] = 'X';
		return (str);
	}
	return (str);
}
