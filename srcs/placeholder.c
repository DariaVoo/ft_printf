/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:36:48 by snorcros          #+#    #+#             */
/*   Updated: 2019/12/07 14:36:50 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_placeholder new_placeholder()
{
	t_placeholder buf;

	buf.flags = FLG_NULL;
	buf.length.flag = "m\0";
	buf.precision = -1;
	buf.width = 0;
	buf.type.flag = 'm';
	buf.sign = 0;
	return (buf);
}

char	*delete_sign(char *str)
{
	size_t i;

	i = 0;
	while (str[i + 1] != '\0')
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}