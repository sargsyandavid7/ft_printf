/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_prec_case_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:20:59 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 03:04:50 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

int	simple_prec_case_hex(t_format *format, char *str, int i)
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
		return (0);
	}
	if (format->hash > 0 && str[0] != '0')
	{
		size += 2;
		if (format->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	size += prec_is_bigger(precision, i, str);
	return (size);
}
