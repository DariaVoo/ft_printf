#include "libft.h"

static int		ft_count_digits(unsigned long long n)
{
	int	count;
	unsigned long long buf;

	count = 0;
	buf = n;
	if (n == 0)
		return (1);
	while (buf > 0)
	{
		buf /= 10;
		count++;
	}
	return (count);
}

static int		ft_count_digits_mantiss(long  double n)
{
	int			count;
	long double buf;
	int			buf2;

	count = 0;
	buf = (unsigned long long int)n;
	buf = n - buf;
	while (buf > 0)
	{
		buf *= 10;
		buf2 = (unsigned long long int)buf;
		buf -= buf2;
		count++;
	}
	return (count);
}

static char			*get_int(unsigned long long n, char *str_n, int count_digits)
{
	size_t i;

	i = count_digits - 1;
	if (n == 0)
		str_n[i] = 0 + 48;
	while (n > 0)
	{
		str_n[i--] = n % 10 + 48;
		n /= 10;
	}
	return (str_n);
}

static char 			*get_mantiss(long double n, char *str_n, int count_digits)
{
	size_t	i;
	int buf;

	i = count_digits;
	n -= (unsigned long long)n;
	if (n != 0)
	{
		str_n[i] = '.';
		i++;
	}
	while (n > 0)
	{
		n *= 10;
		buf = (int)n;
		str_n[i] = buf + '0';
		n -= buf;
		i++;
	}
	return (str_n);
}

char			*ft_itoadouble(long double n)
{
	char	*str_n;
	int		count;
	int		count_digits;

	count_digits = ft_count_digits(n);
	count = count_digits + ft_count_digits_mantiss(n);
	str_n = ft_strnew(count + 1);
	if (!str_n)
		return (NULL);
	str_n = get_int((unsigned long long)n, str_n, count_digits);
	if (str_n[0] == '0')
		return (str_n);
	str_n = get_mantiss(n, str_n, count_digits);
	return (str_n);
}
