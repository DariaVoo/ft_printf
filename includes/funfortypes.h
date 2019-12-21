#ifndef FUNFORTYPES_H
# define FUNFORTYPES_H

#include "libftprintf.h"

t_funtype		types[] =
{
		{'c', ft_c},
		{'%', ft_percent},
		{'d', ft_d},
		{'i', ft_d},
		{'s', ft_s},
		{'x', ft_x},
		{'X', ft_X},
		{'o', ft_o},
		{'u', ft_u},
		{'b', ft_b},
		{'p', ft_p},
		{'f', ft_f},
		{'m', NULL}
};

t_funlenght		lengths[] =
{
		{"ll", length_ll},
		{"hh", length_hh},
		{"l", length_l},
		{"h", length_h},
		{"L", length_L},
		{"z", length_z},
		{"j", length_j},
		{"m", NULL}
};


t_funflags		flags[] =
{
		{ FLG_ZERO,'0', flags_zero},
		{ FLG_PLUS, '+', flags_plus},
		{ FLG_MINUS, '-', flags_minus},
		{ FLG_HASH, '#', flags_hash},//добавить десятичный разделитель для ef, изменить для g
		{ FLG_SPACE, ' ', flags_space},
		{ FLG_NULL, 'm', NULL}
};
#endif