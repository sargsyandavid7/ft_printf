/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdth_and_prec_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:58:17 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/19 17:50:46 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case2(int size, char *str, t_format *format)
{
	size += simple_prec_case_hex(format, str, 0) + ft_strlen(str);
	write(1, str, ft_strlen(str));
	if (format->width > 0)
	{
		if (format->hash > -1)
			format->width -= 2;
		if (format->width < 0)
			format->width = 0;
		size += format->width;
		print_spcs(format->width);
	}
	return (size);
}

static int	case1(int size, char *str, t_format *format)
{
	if (format->minus > -1)
		size += case2(size, str, format);
	else
	{
		if (format->width > 0)
		{
			if (format->hash > -1)
				format->width -= 2;
			if (format->width < 0)
				format->width = 0;
			size += format->width;
			print_spcs(format->width);
		}
		size += ft_strlen(str) + simple_prec_case_hex(format, str, 0);
		write(1, str, ft_strlen(str));
	}
	return (size);
}

int	wdths_and_prec_case_hex(t_format *format, char *str)
{
	int	size;

	size = 0;
	if (format->lenght == -1)
		format->lenght = 0;
	if (str[0] == '0')
	{
		format->hash = -1;
		free(str);
		str = ft_strdup("");
	}
	if (format->lenght > (int)ft_strlen(str))
		format->width -= format->lenght;
	else if (format->lenght == 0 || format->lenght <= (int )ft_strlen(str))
		format->width -= ft_strlen(str);
	size += case1(size, str, format);
	free(str);
	return (size);
}
