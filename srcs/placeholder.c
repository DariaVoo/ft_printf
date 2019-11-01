#include "libftprintf.h"

t_placeholder new_placeholder()
{
	t_placeholder buf;

	buf = (t_placeholder)malloc(sizeof(t_placeholder));
	if (!buf)
		return ((t_placeholder)NULL);
	buf.flags = NULL;
	buf.length = NULL;
	buf.parameter = NULL;
	buf.precision = NULL;
	buf.width = NULL;
	buf.type = NULL;
	return (buf);
}

