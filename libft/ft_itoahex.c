/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:11:11 by snorcros          #+#    #+#             */
/*   Updated: 2019/11/17 17:11:16 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(unsigned int n)
{
	int	count;
	int buf;

	buf = n;
	count = 0;
	while (buf > 0)
	{
		buf /= 16;
		count++;
	}
	return (count);
}

char			*ft_itoahex(unsigned int n, char tcase)
{
	char	*str_n;
	int		count;
	size_t	i;

	count = ft_count_digits(n);
	str_n = ft_strnew(count);
	if (!str_n)
		return (NULL);
	i = count - 1;
	if (n == 0)
		str_n[i] = 0 + 48;
	while (n > 0)
	{
		if ((str_n[i] = n % 16) > 9)
			if (tcase == 'u')
				str_n[i] += 'A' - 10;
			else
				str_n[i] += 'a' - 10;
		else
			str_n[i] += '0';
		n /= 16;
		i--;
	}
	return (str_n);
}
