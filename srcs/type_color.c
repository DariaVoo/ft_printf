
#include "libftprintf.h"
#include "colors.h"

char	*ft_colour(va_list ap)
{
	char	*str;
	char	*buf;
	size_t	i;

	i = 0;
	buf = ft_strmap(va_arg(ap, char *), (char (*)(char))ft_tolower);
	str = ft_strnew(10);
	while (colors[i].color_name[0] != 'z')
	{
		if (ft_strcmp(colors[i].color_name, buf) == 0)
			str = ft_strcpy(str, colors[i].macros);
		i++;
	}
	if (buf)
		free(buf);
	return (str);
}
