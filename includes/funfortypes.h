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
		{'b', ft_b},
		{'m', NULL}
};

t_funlenght	lengths[] =
{

		{"ll", length_ll},
		{"hh", length_hh},
		{"l", length_l},
		{"h", length_h},
		{"L", length_hh},
		{"m", NULL}
};


t_funflags	flags[] =
{
		{'+', flags_plus},
		{'-', NULL},
		{'#', flags_hash},
		{' ', flags_space},
		{'0', flags_zero},
		{'m', NULL}
};
#endif