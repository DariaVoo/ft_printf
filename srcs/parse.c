#include "libftprintf.h"
#include "funfortypes.h"

int	set_type(t_placeholder *pPlaceholder, char *format)
{
	size_t i;

	i = 0;
	while (types[i].flag != 'm')
	{
		if (*format == types[i].flag)
		{
			pPlaceholder->type = types[i];
			return (1);
		}
		i++;
	}
	return 0;
}

int	set_flags(t_placeholder *pPlaceholder, char *format)
{
	size_t i;
	char flags[] = {'+', '-', '#', ' ', ','};

	i = 0;
	//flags = {'+', '-', '#', ' ', ','};
	while (i < 5)
	{
		if (flags[i] == *format)
		{
			pPlaceholder->flags = flags[i];
	//		format++;
			return (1);
		}
		i++;
	}
	return (0);
}

int set_width(t_placeholder *pPlaceholder, char *format, va_list ap)
{
	int w;

	if (*format == '*' && *(format + 1) == '.')
	{
		pPlaceholder->width = va_arg(ap, int);
		return (1);
	}
	else if (*format == '*' && *(format + 1) != '.')
	{
		pPlaceholder->precision = va_arg(ap, int);
		return (1);
	}
	if ((w = ft_atoi(format)) > 0)
	{
		int k;

		k = 0;
		pPlaceholder->width = w;
		while (w > 0)
		{
			w /= 10;
			k++;
		}
		return (k);
	}
	return (0);
}

int set_precision(t_placeholder *pPlaceholder, char *format)
{
	int p;
	int k;

	k = 0;
	if (*format == '.')
	{
		k++;
		format++;
		if ((p = ft_atoi(format)) > 0)
		{

			pPlaceholder->precision = p;
			while (p > 0)
			{
				p /= 10;
				k++;
			}
			return (k);
		}
	}
	return (0);
}

int set_length(t_placeholder *pPlaceholder, char *format)
{
	size_t i;
	char l[] = {'l', 'L', 'h'};

	//l = {'l', 'L', 'h'};
	i = 0;
	while (i < 3)
	{
		if (*format == l[i] && *format != 'L')
		{
			//format++;
			pPlaceholder->length = l[i];
			return (1);
		}
	}
	return (0);
}





