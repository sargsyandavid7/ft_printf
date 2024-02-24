/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_wdth_and_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:19:20 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 03:13:41 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case1(int size, int negative, char *str, t_format *format)
{
	if (format->minus > -1)
	{
		size += simple_prec_case(format, str, negative, 0) + ft_strlen(str);
		write(1, str, ft_strlen(str));
		if (format->width > 0)
		{
			if (negative)
				format->width--;
			size += format->width;
			print_spcs(format->width);
		}
	}
	else
	{
		if (format->width > 0)
		{
			if (negative)
				format->width--;
			size += format->width;
			print_spcs(format->width);
		}
		size += ft_strlen(str) + simple_prec_case(format, str, negative, 0);
		write(1, str, ft_strlen(str));
	}
	return (size);
}

int	wdths_and_prec_case(t_format *format, char *str, int negative)
{
	int	size;

	size = 0;
	if (format->lenght == -1)
		format->lenght = 0;
	if ((format->lenght == 0) && str[0] == '0')
	{
		free(str);
		str = ft_strdup("");
	}
	if (format->lenght > (int)ft_strlen(str))
		format->width -= format->lenght;
	else if (format->lenght == 0 || format->lenght <= (int )ft_strlen(str))
		format->width -= ft_strlen(str);
	size += case1(size, negative, str, format);
	free(str);
	return (size);
}
