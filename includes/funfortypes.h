#ifndef FUNFORTYPES_H
# define FUNFORTYPES_H

#include "libftprintf.h"

t_funtype	types[] =
		{
				{'c', ft_c},
				{'d', ft_d},
				{'i', ft_d},
				{'s', ft_s},
				{'x', ft_x},
				{'X', ft_X},
				{'o', ft_o},
				{'u', ft_u},
				{'m', NULL}
		};

t_funlenght	lengths[] =
{
		{"l", length_l},
		{"ll", length_ll},
		{"h", length_h},
		{"hh", length_hh},
		{"L", length_hh},
		{"m", NULL}
};
#endif