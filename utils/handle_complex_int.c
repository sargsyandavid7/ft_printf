/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_complex_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:34:37 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 02:25:53 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// CASE OF NORMAL SIMPLE CASES WHEN LENGHT AND WIDTH ARE LESS THAN STRLEN
static int	normal_case(t_format *format, char *str, int negative)
{
	int	size;

	size = ft_strlen(str);
	if (negative)
	{
		size++;
		write(1, "-", 1);
	}
	if (format->plus > -1 && !negative)
	{
		size++;
		write(1, "+", 1);
	}
	if (format->space > -1 && !negative)
	{
		size++;
		write(1, " ", 1);
	}
	write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

// MAIN FUNCTION
int	handle_complex_int(t_format *format, va_list arg_list)
{
	long	value;
	char	*str;
	int		negative;

	if (format->type == 'd' || format->type == 'i')
		value = va_arg(arg_list, int);
	else
		value = va_arg(arg_list, unsigned int);
	negative = 0;
	if (value < 0)
	{
		value = -value;
		negative = 1;
	}
	str = ft_itoa(value);
	if (format->precision > -1 && format->width >= (int )ft_strlen(str))
		return (wdths_and_prec_case(format, str, negative));
	if (format->width >= (int )ft_strlen(str) && format->precision == -1)
		return (widths_case_only(format, str, negative, 1));
	if (format->width <= (int )ft_strlen(str) && format->precision == -1)
		return (normal_case(format, str, negative));
	if ((format->width == -1 || format->width <= (int )ft_strlen(str))
		&& format->precision > -1)
		return (simple_prec_case(format, str, negative, 1));
	return (0);
}
