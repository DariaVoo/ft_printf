#include "libftprintf.h"

char *flags_plus(char *str)
{
	if (str[0] != '-')
		return (ft_stradd_front(str, ft_strlen(str) + 1, '+'));
	return (str);
}

char *flags_space(char *str)
{
	if (str[0] != '-')
		return (ft_stradd_front(str, ft_strlen(str) + 1, ' '));
	return (str);
}

char *flags_zero(char *str, t_placeholder place)
{
	if (place.type.flag == 'd' || place.type.flag == 'i' || place.type.flag == 'o'
			|| place.type.flag == 'u' || place.type.flag == 'x' || place.type.flag == 'X')
		return (ft_strreplace(str, ' ', '0'));
	else
		return (str);
}

char *flags_hash(char *str)
{
	if (place.type.flag == 'o')
		return (ft_stradd_front(str, ft_strlen(str) + 1, '0'));
	else if (place.type.flag == 'x')
	{
		str = ft_stradd_front(str,ft_strlen(str) + 2, '0');
		str[1] = 'x';
		return (str);
	}
	else if (place.type.flag == 'X')
	{
		str = ft_stradd_front(str,  ft_strlen(str) + 2, '0');
		str[1] = 'X';
		return (str);
	}

	return (str);
}
