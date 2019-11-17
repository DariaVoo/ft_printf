/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:39:03 by snorcros          #+#    #+#             */
/*   Updated: 2019/11/07 11:09:10 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include "libft.h"
#include <stdarg.h>

typedef struct s_funtype
{
	char	flag;
	char	*(*fun)(va_list);
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





int				ft_printf(const char *format, ...);

t_placeholder	new_placeholder();
int 			set_type(t_placeholder *pPlaceholder, const char *format);
int 			set_flags(t_placeholder *pPlaceholder, const char *format);
int 			set_width(t_placeholder *pPlaceholder, const char *format, va_list ap);
int 			set_precision(t_placeholder *pPlaceholder, const char *format);
int 			set_length(t_placeholder *pPlaceholder, const char *format);

//char			*type_to_char(t_funtype ftype, va_list ap);

char			*to_str_logic(t_placeholder place, va_list ap);
int				print_this(t_placeholder place, char *str);
char			*ft_c(va_list ap);
char			*ft_d(va_list ap);
char 			*ft_s(va_list ap);
char 			*ft_x(va_list ap);
char 			*ft_X(va_list ap);
char 			*ft_o(va_list ap);
char			*ft_u(va_list ap);
#endif
