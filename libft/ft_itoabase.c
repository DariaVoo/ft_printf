/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:58:49 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/12 20:51:50 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(unsigned int n, unsigned int base)
{
	int	count;
	int buf;

	buf = n;
	count = 0;
	while (buf > 0)
	{
		buf /= base;
		count++;
	}
	return (count);
}

char			*ft_itoabase(unsigned int n, unsigned int base)
{
	char	*str_n;
	int		count;
	size_t	i;

	count = ft_count_digits(n, base);
	str_n = ft_strnew(count);
	if (!str_n)
		return (NULL);
	i = count - 1;
	if (n == 0)
		str_n[i] = 0 + 48;
	while (n > 0)
	{
		str_n[i--] = n % base + 48;
		n /= base;
	}
	return (str_n);
}
