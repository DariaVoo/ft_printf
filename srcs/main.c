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
	printf("% u\n", 4294967295);
	ft_printf("% u\n", 4294967295);
	/*
	printf("%hd\n", 32768);
	ft_printf("%hd\n", 32768);

	printf("%0+5d\n", -42);
	ft_printf("%0+5d\n", -42);

 	printf("@moulitest: %o\n", 0);
	ft_printf("@moulitest: %o\n", 0);

	printf("%#-08x", 42);
	printf("$\n");
	ft_printf("%#-08x", 42);
	printf("$\n");

 * printf("%#x\n", 0);
	ft_printf("%#x\n", 0);
	printf("%#08x\n", 42);
	ft_printf("%#08x\n", 42);
	printf("%# 8x\n", 42);
	ft_printf("%# 8x\n", 42);

	printf("%   %\n", "test");
	ft_printf("%   %\n", "test");

	printf("%%\n");
	ft_printf("%%\n");
	int b = 3;
	void *p = &b;

	printf("pointer %p\n", p);
	ft_printf("pointer %p\n", p);

	char *str = "aaaa\0";
	unsigned int ui = 933;
	long unsigned int lui = 933;
	long long unsigned int llui = 933;
	long long int lli = -933;
	long int li = -933;
	short int si = -4;
	signed char kek = -124;

	printf("+ %+010d\n", 23);
	printf("+ %+010d\n", -23);
	printf("0 %010d\n", -23);
	printf("0 %010d\n", 23);
	//printf("space % d\n", 23);
	//printf("0 %015d\n", 13);
	//printf("# %#x\n", 12);
	printf("---------------\n");
	ft_printf("+ %+010d\n", 23);
	ft_printf("+ %+010d\n", -23);
	ft_printf("0 %010d\n", -23);
	ft_printf("0 %010d\n", 23);
	//ft_printf("space % d\n", 23);
	//ft_printf("0 %015d\n", 13);
	//ft_printf("# %#x\n", 12);
/*
	printf("%-*s",20, "this is a test");
	printf("$\n");
	ft_printf("%-*s", 20, "this is a test");
	printf("$\n");
	//printf("%20s", "\n$this is a test");
 	//length
	//signed
	ft_printf("length signed\n");
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
	ft_printf("%s","---------------------\n");

 	//unsigned
	ft_printf("length unsigned\n");
	printf("printf 10 llu: %llu\n", llui);
	printf("16 llx: %llx\n", llui);
	printf("16 llX: %llX\n", llui);
	printf("8 llo: %llo\n", llui);
	ft_printf("%s","---------------------\n");
	ft_printf("ft_printf 10 llu: %llu\n", llui);
	ft_printf("16 llx: %llx\n", llui);
	ft_printf("16 llX: %llX\n", llui);
	ft_printf("8 llo: %llo\n", llui);

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
*/
	/**easy test
	ft_printf("kekeke\n");
	ft_printf("10 u: %u\n", ui);
	ft_printf("16 x: %x\n", ui);
	ft_printf("16 X: %X\n", ui);
	ft_printf("8 o: %o\n", ui);
	ft_printf("string: %s\n", str);
	ft_printf("kekeke\n");
	ft_printf("this is char: %c\n", 'g');
	ft_printf("this is int: %d\n", 2568);
	 */
	return (0);
}
