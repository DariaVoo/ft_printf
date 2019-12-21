
#include "libftprintf.h"

static size_t	strcount_digit(char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '.' && str[count] != '\0')
		count++;
	if (str[count + 1] != '\0')
		count++;
	return (count);
}

static size_t	str_len_mantiss(char *str)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char *get_precision_float(t_placeholder *place, char *ans)
{
	size_t count_digit;
	size_t	i;

	count_digit = strcount_digit(ans);
	if (place->precision == 0)
		return (ft_strcut(ans, count_digit));
	else if ((size_t)place->precision > str_len_mantiss(ans))
		return (ft_stradd_back(ans, place->precision + count_digit, '0', place->type.flag));
	if (ans[place->precision + count_digit] >= '5')
	{
		i = 1;
		if (ans[place->precision + count_digit - i] != '9')
			ans[place->precision + count_digit - i] += 1;
		else {
			while (ans[place->precision + count_digit - i] == '9') {
				ans[place->precision + count_digit - i] = '0';
				i++;
			}
			ans[place->precision + count_digit - i] += 1;
		}
	}
	return (ft_strcut(ans, place->precision + count_digit));
}

char *get_precision(t_placeholder *place, char *ans)
{
	if (place->type.flag == 'c' || (place->type.flag == 'o' &&
									(place->flags & FLG_HASH) != 0 && *ans == '0'))
		return (ans);
	if (place->type.flag == 'f')
		return (get_precision_float(place, ans));
	else if (place->precision == 0 && *ans == '0')
	{
		free(ans);
		place->flags &= FLG_NULL;
		return (ft_strnew(1));
	}
	else if ((place->type.flag == 'd' || place->type.flag == 'i' || place->type.flag == 'o'
			  || place->type.flag == 'u' || place->type.flag == 'x' || place->type.flag == 'X')
			 && (place->precision > 0 && (size_t)place->precision > ft_strlen(ans) && *ans != '\0'))
	{
		place->flags &= ~FLG_ZERO;
		ans = ft_stradd_front(ans, place->precision, '0', place->type.flag);
	}
	else if (place->type.flag == 's' && place->precision >= 0)
		ans = ft_strcut(ans, ft_strlen(ans) - place->precision);
	return (ans);
}
