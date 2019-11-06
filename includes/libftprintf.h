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

typedef struct s_funtype
{
	char	flag;
	char	*(*fun)(void *);
}				t_funtype;

typedef struct s_placeholder
{
	//int         parameter;
    char        flags;
    int         width;
    int         precision;
    char        length;
    t_funtype	type;
}               t_placeholder;

int				ft_printf(const char * restrict format, ...);

t_placeholder	new_placeholder();
int 			set_type(t_placeholder *pPlaceholder, char *format);
int 			set_flags(t_placeholder *pPlaceholder, char *format);
int 			set_width(t_placeholder *pPlaceholder, char *format, va_list ap);
int 			set_precision(t_placeholder *pPlaceholder, char *format);
int 			set_length(t_placeholder *pPlaceholder, char *format);

char			*to_str_logic(t_placeholder place, va_list ap);
char			*ft_c(va_list ap);
int				print_this(char *str);

t_funtype	types[] =
{
		{'c', ft_c},
		//{'s', ft_putstr},
		{'m', NULL}
};