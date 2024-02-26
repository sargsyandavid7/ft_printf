/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_complex_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:55:56 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/26 17:11:15 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (0);
}

int	normal_case_hex(t_format *format, char *str)
{
	int	size;

	size = 0;
	if (format->hash > -1 && (str[0] != '0' || format->type == 'p'))
	{
		size += 2;
		if (format->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	write(1, str, ft_strlen(str));
	size += ft_strlen(str);
	free(str);
	return (size);
}

int	handle_complex_hex(t_format *format, va_list args_lst)
{
	unsigned int	value;
	char			*hex_str;
	int				len;

	value = va_arg(args_lst, unsigned int);
	hex_str = translate_to_hex(value);
	len = ft_strlen(hex_str);
	if (format->type == 'X')
		ft_strtoupper(hex_str);
	if (format->width == -1)
		format->width = 0;
	if (format->precision > -1 && format->width >= (int )ft_strlen(hex_str))
		return (wdths_and_prec_case(format, hex_str, 0));
	if (format->width <= len && format->precision == -1)
		return (normal_case_hex(format, hex_str));
	if (format->width > len && format->precision == -1)
		return (widths_case_only_hex(format, hex_str, 1));
	if ((format->width == -1 || format->width <= len)
		&& format->precision > -1)
		return (simple_prec_case_hex(format, hex_str, 1));
	return (0);
}
