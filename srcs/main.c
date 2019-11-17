/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:34:25 by snorcros          #+#    #+#             */
/*   Updated: 2019/11/07 11:16:50 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char *str = "aaaa\0";

	printf("string: %s\n", str);
	ft_printf("string: %s\n", str);
	ft_printf("kekeke\n");
	//ft_printf("%%\n");
	ft_printf("this is char: %c\n", 'g');
	ft_printf("this is int: %d\n", 2568);
	return (0);
}
