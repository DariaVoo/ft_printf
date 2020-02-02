/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:10:26 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/01 18:13:07 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char 	buf;
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		buf = ft_tolower(str[i]);
		str[i] = buf;
		i++;
	}
	return (str);
}
