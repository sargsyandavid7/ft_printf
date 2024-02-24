/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:20:39 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/24 14:37:09 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_simple_pointer(char *str,
		unsigned long long value)
{
	int	size;

	size = 0;
	if (value == 0)
	{
		free(str);
		str = "(null)";
	}
	else
	{
		write(1, "0x", 2);
		size += 2;
	}
	write(1, str, ft_strlen(str));
	size += ft_strlen(str);
	if (value != 0)
		free(str);
	return (size);
}

static int	handle_complex_pointer(t_format *format, char *ptr_str,
	unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		ptr_str = ft_strdup("(null)");
	len = ft_strlen(ptr_str);
	if (ptr != 0)
		format->hash = 1;
	if (format->width == -1)
		format->width = 0;
	if (format->precision > -1 && format->width >= len)
		return (wdths_and_prec_case(format, ptr_str, 0));
	if (format->width <= len && format->precision == -1)
		return (normal_case_hex(format, ptr_str));
	if (format->width > len && format->precision == -1)
		return (widths_case_only_hex(format, ptr_str, 1));
	if ((format->width == -1 || format->width <= len)
		&& format->precision > -1)
		return (simple_prec_case_hex(format, ptr_str, 1));
	return (0);
}


int	handle_pointer(t_format *format, va_list args_lst)
{
	unsigned long		value;
	char				*str;
	int					size;

	value = va_arg(args_lst, unsigned long);
	str = translate_to_hex(value);
	if (!str)
		return (0);
	if (check_if_simple(format))
		size = handle_simple_pointer(str, value);
	else
		size = handle_complex_pointer(format, str, value);
	return (size);
}
