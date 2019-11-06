#include "libftprintf.h"

t_placeholder new_placeholder()
{
	t_placeholder buf;

	buf = (t_placeholder)malloc(sizeof(t_placeholder));
	if (!buf)
		return ((t_placeholder)NULL);
	buf.flags = (char)0;
	buf.length = (char)0;
	buf.precision = 0;
	buf.width = 0;
	buf.type = (t_funtype)0;
	return (buf);
}

