#include "libft.h"

char 	*ft_strcreate(char	*str)
{
	char	*malloc_str;

	malloc_str = ft_strnew(ft_strlen(str));
	malloc_str = ft_strcpy(malloc_str, str);
	return (malloc_str);
}
