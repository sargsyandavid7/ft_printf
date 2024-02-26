/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:20:39 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/26 18:23:30 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_simple_pointer(char *str)
{
	int	size;

	size = 0;
	write(1, "0x", 2);
	write(1, str, ft_strlen(str));
	size += ft_strlen(str) + 2;
	free(str);
	return (size);
}

static int	handle_complex_pointer(t_format *format, char *ptr_str)
{
	int	len;

	len = ft_strlen(ptr_str);
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
		size = handle_simple_pointer(str);
	else
		size = handle_complex_pointer(format, str);
	return (size);
}
