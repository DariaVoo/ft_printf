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
	unsigned int ui = 933;
	//t long unsigned int lui = 933;
	//signed char kek = -128;

	//ft_printf("signed char %hhi\n", kek);
	//printf("signed char %hhi\n", kek);
	//printf("this is char : %hi\n", -103);
	/*printf("printf 10 lu: %lu\n", lui);
	printf("16 lx: %lx\n", lui);
	printf("16 lX: %lX\n", lui);
	printf("8 lo: %lo\n", lui);
	//ft_printf("%s","---------------------\n");
	ft_printf("printf 10 lu: %lu\n", lui);
	ft_printf("16 lx: %lx\n", lui);
	ft_printf("16 lX: %lX\n", lui);
	ft_printf("8 lo: %lo\n", lui);
*/
	ft_printf("kekeke\n");
	ft_printf("10 u: %u\n", ui);
	ft_printf("16 x: %x\n", ui);
	ft_printf("16 X: %X\n", ui);
	ft_printf("8 o: %o\n", ui);
	//printf("string: %s\n", str);
	ft_printf("string: %s\n", str);
	ft_printf("kekeke\n");
	//ft_printf("%%\n");
	ft_printf("this is char: %c\n", 'g');
	ft_printf("this is int: %d\n", 2568);
	return (0);
}
