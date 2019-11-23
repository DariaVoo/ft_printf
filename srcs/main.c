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
	//char *str = "aaaa\0";
	//unsigned int ui = 933;
	//long long unsigned int lui = 933;
	//long long int lli = -933;
	//long int li = -933;
	//short int si = -4;
	//signed char kek = -128;

	printf("%-*s",20, "this is a test");
	printf("$\n");
	ft_printf("%-*s", 20, "this is a test");
	printf("$\n");
	//printf("%20s", "\n$this is a test");

/*	//signed
	ft_printf("short int %hi\n", si);
	printf("short int %hi\n", si);

	ft_printf("%s","---------------------\n");
	ft_printf("signed char %hhi\n", kek);
	printf("signed char %hhi\n", kek);

	ft_printf("%s","---------------------\n");
	printf("ft_printf 10 ld: %ld\n", li);
	ft_printf("printf 10 ld: %ld\n", li);

	ft_printf("%s","--------------------\n");
	printf("ft_printf 10 lld: %lld\n", lli);
	ft_printf("printf 10 lld: %lld\n", lli);

 	//unsigned
	ft_printf("%s","---------------------\n");
	printf("ft_printf 10 llu: %llu\n", lui);
	printf("16 llx: %llx\n", lui);
	printf("16 llX: %llX\n", lui);
	printf("8 llo: %llo\n", lui);
	ft_printf("%s","---------------------\n");
	ft_printf("printf 10 llu: %llu\n", lui);
	ft_printf("16 llx: %llx\n", lui);
	ft_printf("16 llX: %llX\n", lui);
	ft_printf("8 llo: %llo\n", lui);

	printf("ft_printf 10 llu: %llu\n", lui);
	printf("16 llx: %llx\n", lui);
	printf("16 llX: %llX\n", lui);
	printf("8 llo: %llo\n", lui);
	ft_printf("%s","---------------------\n");
	ft_printf("printf 10 llu: %llu\n", lui);
	ft_printf("16 llx: %llx\n", lui);
	ft_printf("16 llX: %llX\n", lui);
	ft_printf("8 llo: %llo\n", lui);

	printf("this is char : %hi\n", -103);
	printf("ft_printf 10 lu: %lu\n", lui);
	printf("16 lx: %lx\n", lui);
	printf("16 lX: %lX\n", lui);
	printf("8 lo: %lo\n", lui);
	ft_printf("%s","---------------------\n");
	ft_printf("printf 10 lu: %lu\n", lui);
	ft_printf("16 lx: %lx\n", lui);
	ft_printf("16 lX: %lX\n", lui);
	ft_printf("8 lo: %lo\n", lui);

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
	 */
	return (0);
}
