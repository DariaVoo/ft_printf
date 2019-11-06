#include "libftprintf.h"

char *ft_c(va_list ap)
{
	char *ans;
	if (!(ans = ft_strnew(2)))
		return (NULL);
	ans[0] = va_arg(ap, char);
	ans[1] = '\0';
	return (ans);
}
