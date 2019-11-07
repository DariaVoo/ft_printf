#include "libftprintf.h"

t_placeholder new_placeholder()
{
	t_placeholder buf;

	buf.flags = (char)0;
	buf.length = (char)0;
	buf.precision = 0;
	buf.width = 0;
	buf.type.flag = 'm';
	return (buf);
}

