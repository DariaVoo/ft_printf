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

char	*ft_percent(va_list ap)
{
	char *ans;

	if (!(ans = ft_strnew(2)) || ap == NULL)
		return (NULL);
	ans[0] = '%';
	ans[1] = '\0';
	return (ans);
}

char	*ft_d(va_list ap)
{
	return (ft_itoa(va_arg(ap, int)));
}

char	*ft_s(va_list ap)
{
	char	*str;
	char	*buf;

	buf = va_arg(ap, char *);
	if (buf == NULL)
	{
		str = ft_strnew(6);
		str = ft_strcpy(str, "(null)\0");
	}
	else if (*buf == '\0')
		str = ft_strnew(1);
	else
	{
		str = ft_strnew(ft_strlen(buf));
		str = ft_strcpy(str, buf);
	}
	return (str);
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

char	*ft_f(va_list ap)
{
	long double number;
	char 		*str;

	number =  va_arg(ap, double);
	if (number != number)
	{
		str = ft_strnew(5);
		if (number > 0)
			return (ft_strcpy(str, "nan\0"));
		else
			return (ft_strcpy(str, "-nan\0"));
	}
	else if (number != 0 && number * 10 == number)
	{
		str = ft_strnew(5);
		if (number > 0)
			return (ft_strcpy(str, "inf\0"));
		else
			return (ft_strcpy(str, "-inf\0"));
	}
	return (ft_itoadouble(number));
}

char	*ft_p(va_list ap)
{
	char *str;

	str = ft_itoahex((unsigned long long)va_arg(ap, void *), 'l');
	if (*str == '0')
	{
		free(str);
		str = ft_strnew(5);
		str = ft_strcpy(str, "(nil)\0");
	}
	else
	{
		str = ft_stradd_front(str, ft_strlen(str) + 2, '0', 'p');
		str[1] = 'x';
	}
	return (str);
}
