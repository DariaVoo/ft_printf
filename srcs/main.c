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
/*
#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%C now is red %C ifs EOF %C is BLUE %C is green\n"
		   "", "red", "eof", "blue", "green");
	return (0);
}
*/
/*ft_printf("% h");
	printf("$\n");
	//ft_printf("% ");
	printf("$\n");

	*printf("%5+dxx", -42);
	printf("$\n");
	printf("%5+d", -42);
	printf("$\n");
	printf("%5+   ");
	printf("$\n");
	printf("%+5 kekeriki");
	printf("$\n");
	printf("%+5");
	printf("$\n");
	printf("%jzd", 4);

	printf("{%*3d}\n", 5, 0);
	ft_printf("{%*3d}", 5, 0);

	printf("%05c\n", 42);
	ft_printf("%05c", 42);

	printf("%010s is a string\n", "this");
	ft_printf("%010s is a string", "this");
	long double nan = 0.0 / 0.0;

	printf("%Lf\n", 0.0 / 0.0);//втф
	ft_printf("%Lf\n", 0.0 / 0.0);
	printf("%Lf\n", nan);
	ft_printf("%Lf\n", nan);

	long double posinf = 5.0 / 0.0;
	long double neginf = -5.0 / 0.0;
	printf("%.40Lf\n", -3.444999);//WTF
	ft_printf("%.40Lf\n", -3.444999);
	printf("%5.40Lf\n", posinf);
	ft_printf("%5.40Lf\n", posinf);
	printf("%5.40Lf\n", neginf);
	ft_printf("%5.40Lf\n", neginf);
	printf("%5.40Lf\n", nan);
	ft_printf("%5.40Lf\n", nan);

	printf("%.50f\n", -3.14);
	printf("%.30f\n", -3.14);
	ft_printf("%.30f\n", -3.14);

	double a = 20;
	printf("%.0f\n", a);
	ft_printf("%.0f\n", a);

	printf("{%*3d}\n", 5, 0);
	ft_printf("{%*3d}\n", 5, 0);

	printf("%*.*d\n", 0, 3, 0);
	ft_printf("%*.*d\n", 0, 3, 0);
	printf("%#.3o\n", 1);
	ft_printf("%#.3o\n", 1);
	*
	printf("%.p$ %.0p\n", 0, 0);
	ft_printf("%.p$ %.0p", 0, 0);
	//NEED TO FIXprintf("aaaaa%   $");
	*
	printf("%2c$\n", 0);
	ft_printf("%2c$\n", 0);

	printf("%.0s$\n", "aaa");
	ft_printf("%.0s$\n", "aaa");

	printf("@moulitest: %.d$ %.0d$\n", 42, 43);
	ft_printf("@moulitest: %.d$ %.0d$\n\n", 42, 43);

	printf("@moulitest: %5.x$ %5.0x$\n", 0, 0);
	ft_printf("@moulitest: %5.x$ %5.0x$\n\n", 0, 0);
	printf("@moulitest: %5.o$ %5.0o$\n", 0, 0);
	ft_printf("@moulitest: %5.o$ %5.0o$\n\n", 0, 0);
	printf("@moulitest: %.x$ %.0x$\n", 0, 0);
	ft_printf("@moulitest: %.x$ %.0x$\n\n", 0, 0);
	printf("@moulitest: %.o$ %.0o$\n", 0, 0);
	ft_printf("@moulitest: %.o$ %.0o$\n\n", 0, 0);
	printf("@moulitest: %#.o$ %#.0o$\n", 5, 5);
	ft_printf("@moulitest: %#.o$ %#.0o$\n\n", 5, 5);

	//ft_printf("@moulitest: %#.d$ %#.0d$\n\n", 0, 0);
	//ft_printf("%5.0x$\n", 0);
	//ft_printf("%c", 0);

	printf("%-5.2s is a string\n", "");
	ft_printf("%-5.2s is a string\n", "");

	printf("%-5.2s is a string\n", "this");
	ft_printf("%-5.2s is a string\n", "this");

	//printf("%.2s is a string\n", "");
	//ft_printf("%.2s is a string\n", "");

	  //работает тут, а в тестах какая-то дичь
	printf("%lld\n", LLONG_MIN);
	ft_printf("%lld\n", LLONG_MIN);

	printf("%05d\n", -42);
	ft_printf("%05d\n", -42);

	printf("%0d\n", -42);
	ft_printf("%0d\n", -42);

	printf("%-#6o", 2500);
	printf("$\n");
	ft_printf("%-#6o", 2500);
	printf("$\n");

	printf("%.2c\n", NULL);//надо добавить
	ft_printf("%.2c\n", NULL);

	printf("%#08x\n", 42);
	ft_printf("%#08x\n", 42);

	printf("printf :%.0%\n");
	ft_printf("ft :%.0%\n");

	printf("% u\n", 4294967295);
	ft_printf("% u\n", 4294967295);

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

	**easy test
	ft_printf("kekeke\n");
	ft_printf("10 u: %u\n", ui);
	ft_printf("16 x: %x\n", ui);
	ft_printf("16 X: %X\n", ui);
	ft_printf("8 o: %o\n", ui);
	ft_printf("string: %s\n", str);
	ft_printf("kekeke\n");
	ft_printf("this is char: %c\n", 'g');
	ft_printf("this is int: %d\n", 2568);
*
	return (0);
}
*/