/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:33 by snorcros          #+#    #+#             */
/*   Updated: 2019/10/13 15:33:04 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int		parse_format(char *str)
{
	size_t	i;

	i = 0;
	while (i < 2)
	{
		if (*str == flfun[i].flag)
			return (flfun[i].fun())
	}
}*/

int		printf(const char * restrict format, ...)
{
	int		count;
	va_list	ap;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format)
	{
		while (*format != '%' && format)
		{
			count += ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
			while (i < 2)
			{
				if (*format == flfun[i].flag)
					count += flfun[i].fun(va_arg(ap, flfun[i].TYPE));
				i++;
			}
		}
	}
	va_end(ap);
	return (count);
}
