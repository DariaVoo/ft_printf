#include "libftprintf.h"
<<<<<<< HEAD

char *ft_c(va_list ap)
{
	char *ans;
	if (!(ans = ft_strnew(2)))
=======
/*
char *ft_c(va_list ap)
{
	char *ans;

	if (!(ans = ft_strnew(2))
>>>>>>> b054e72903147d4b368f00401b2255039e7beecb
		return (NULL);
	ans[0] = va_arg(ap, char);
	ans[1] = '\0';
	return (ans);
}
<<<<<<< HEAD
=======
*/
>>>>>>> b054e72903147d4b368f00401b2255039e7beecb
