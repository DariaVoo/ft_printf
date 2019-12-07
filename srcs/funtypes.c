/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:14:01 by snorcros          #+#    #+#             */
/*   Updated: 2019/12/07 14:36:20 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_c(va_list ap)
{
	char *ans;

	if (!(ans = ft_strnew(2)))
		return (NULL);
	ans[0] = (char)va_arg(ap, int);
	ans[1] = '\0';
	return (ans);
}

char	*ft_d(va_list ap)
{
	return (ft_itoa(va_arg(ap, int)));
}

char	*ft_s(va_list ap)
{
	return (va_arg(ap, char *));
}

char	*ft_x(va_list ap)
{
	return (ft_itoahex(va_arg(ap, unsigned int), 'l'));
}

char	*ft_X(va_list ap)
{
	return (ft_itoahex(va_arg(ap, unsigned int), 'u'));
}

char	*ft_o(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)8));
}

char	*ft_u(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)10));
}

char	*ft_b(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)2));
}

char	*ft_p(va_list ap)
{
	char *str;

	str = ft_itoahex((unsigned long long)va_arg(ap, void *), 'l');
	str = ft_stradd_front(str, ft_strlen(str) + 2, '0', 'p');
	str[1] = 'x';
	return (str);
}
