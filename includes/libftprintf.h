/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:39:03 by snorcros          #+#    #+#             */
/*   Updated: 2019/10/13 15:46:12 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include "types.h"

typedef enum {
	CHAR,
	STRING
} TYPE;

typedef struct s_fun_flag
{
	char	flag;
	TYPE	type;
	int		(*fun)(char *);
}				t_fun_flag;

t_fun_flag	flfun[] = 
{
	{'c', CHAR, ft_putchar},
	{'s', STRING, ft_putstr},
};

int		printf(const char * restrict format, ...);
