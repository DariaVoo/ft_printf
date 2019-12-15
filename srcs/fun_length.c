/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:35:38 by snorcros          #+#    #+#             */
/*   Updated: 2019/12/07 14:35:43 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_l(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')//error
		return (ft_itoa_signed(va_arg(ap, long int), 10));
	if (typeflag == 'u')
		return (ft_itoabase(va_arg(ap, unsigned long int), 10));
	else if (typeflag == 'o')
		return (ft_itoabase(va_arg(ap, unsigned long int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex(va_arg(ap, unsigned long int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex(va_arg(ap, unsigned long int), 'u'));
	return (NULL);
}

char	*length_ll(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')//error
		return (ft_itoa_signed(va_arg(ap, long int), 10));
	if (typeflag == 'u')
		return (ft_itoabase(va_arg(ap, unsigned long long int), 10));
	else if (typeflag == 'o')
		return (ft_itoabase(va_arg(ap, unsigned long long int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex(va_arg(ap, unsigned long long int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex(va_arg(ap, unsigned long long int), 'u'));
	return (NULL);
}

char	*length_h(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa((short int)va_arg(ap, int)));
	else if (typeflag == 'u')
		return (ft_itoabase((unsigned short)va_arg(ap, unsigned int), 10));
	else if (typeflag == 'o')
		return (ft_itoabase((unsigned short)va_arg(ap, unsigned int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex((unsigned short)va_arg(ap, unsigned int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex((unsigned short)va_arg(ap, unsigned int), 'u'));
	return (NULL);
}

char	*length_hh(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa((short)va_arg(ap, int)));
	if (typeflag == 'u')
		return (ft_itoabase((unsigned char)va_arg(ap, unsigned int), 10));
	else if (typeflag == 'o')
		return (ft_itoabase((signed char)va_arg(ap, unsigned int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex((signed char)va_arg(ap, unsigned int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex((signed char)va_arg(ap, unsigned int), 'u'));
	return (NULL);
}
