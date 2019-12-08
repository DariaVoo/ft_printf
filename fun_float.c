
#include "libftprintf.h"

static int		ft_count_digits(long double n)
{
	int	count;
	long long int buf;

	count = 0;
	buf = (long long int)n;
	buf = n;
	if (n <= 0)
	{
		buf *= -1;
		count++;
	}
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
	buf = (long long int)n;
	buf = n - buf;
	while (buf > 0)
	{
		buf = buf * 10;
		buf2 = (int)buf;
		buf -= buf2;
		count++;
	}
	return (count);
}

static int		order_to_str(long long int n, char *str)
{
	size_t i;
	long long int buf;

	i = 0;
	buf = n;
	if (n <= 0)
	{
		str[i] = '-';
		buf *= -1;
		i++;
	}
	if (n == 0)
		str_n[i] = 0 + 48;
	while (buf > 0)
	{

	}
	return (count);
}
char			*ft_itoadouble(long double n)
{
	char	*str_n;
	int		count;
	int		buff;
	size_t	i;

	count = ft_count_digits(n, base);
	count += ft_count_digits_mantiss(n, base);
	str_n = ft_strnew(count);
	if (!str_n)
		return (NULL);
	i = 0;
	if (n < 0)
	{

		str_n[i] = '-';
	}
	if (n == 0)
		str_n[i] = 0 + 48;

	while (n > 0)
	{

		str_n[i--] = n % base + 48;
		n /= base;
	}
	return (str_n);
}
