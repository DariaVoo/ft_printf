/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:39:03 by snorcros          #+#    #+#             */
/*   Updated: 2019/10/27 14:50:51 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

typedef struct placeholder
{
    int         parameter;
    char        *flags;
    int         width;
    int         precision;
    int         length;
}               t_placeholder;

typedef struct s_fun_flag
{
	char	flag;
	int		(*fun)(char *);
}				t_fun_flag;

t_fun_flag	flfun[] = 
{
	{'c', ft_putchar},
	{'s', ft_putstr},
};

int		ft_printf(const char * restrict format, ...);
