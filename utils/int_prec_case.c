/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_prec_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:34:03 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/17 12:39:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prec_is_bigger(int precision, int i, char *str)
{
	int	size;
	int	len;

	size = 0;
	len = ft_strlen(str);
	if (precision > len)
	{
		size += precision - len;
		print_zeros(precision - len);
	}
	if (i)
	{
		write(1, str, len);
		size += len;
		free(str);
	}
	return (size);
}

int	simple_prec_case(t_format *format, char *str, int negative, int i)
{
	int	size;
	int	precision;

	size = 0;
	precision = format->lenght;
	if (precision == -1)
		precision = 0;
	if ((precision == 0) && str[0] == '0' && i)
	{
		free(str);
		str = ft_strdup("");
	}
	if (negative)
		write(1, "-", 1);
	if (format->plus > -1 && !negative && ++size)
		write(1, "+", 1);
	if (format->space > -1 && !negative && ++size)
		write(1, " ", 1);
	size += prec_is_bigger(precision, i, str) + negative;
	return (size);
}
