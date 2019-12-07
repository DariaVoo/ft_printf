/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:36:48 by snorcros          #+#    #+#             */
/*   Updated: 2019/12/07 14:36:50 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_placeholder new_placeholder()
{
	t_placeholder buf;

	buf.flags.flag = 'm';
	buf.length.flag = "m\0";
	buf.precision = 0;
	buf.width = 0;
	buf.type.flag = 'm';
	return (buf);
}

