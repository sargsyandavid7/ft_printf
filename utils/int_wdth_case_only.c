/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_wdth_case_only.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:29:18 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 03:12:02 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	minus_case(t_format *format, char *str, int negative, int i)
{
	int	size;
	int	width;

	size = 0;
	width = format->width - ft_strlen(str) - negative;
	size += print_logic(negative, format, width, size);
	if (i)
	{
		write(1, str, ft_strlen(str));
		size += ft_strlen(str) + negative;
	}
	if (width > 0)
	{
		size += width;
		print_spcs(width);
	}
	return (size);
}

static int	non_minus_zero(t_format *format, int negative, char *str, int i)
{
	int	size;
	int	width;

	size = 0;
	width = format->width;
	width -= ft_strlen(str) + negative;
	size += print_logic(negative, format, width, size);
	if (width > 0)
	{
		size += width;
		print_zeros(width);
	}
	if (i)
	{
		write(1, str, ft_strlen(str));
		size += ft_strlen(str) + negative;
	}
	return (size);
}

static int	int_non_m_non_z_case(t_format *format, int negative,
	int width)
{
	int	size;

	size = 0;
	if (negative)
		write(1, "-", 1);
	if (format->plus > -1 && !negative)
	{
		write(1, "+", 1);
		if (width <= 0)
			size++;
	}
	if (format->space > -1 && !negative)
	{
		if (width <= 0)
			size++;
		write(1, " ", 1);
	}
	return (size);
}

static int	non_minus_non_zero(t_format *format, int negative, char *str, int i)
{
	int	size;
	int	width;

	size = 0;
	width = format->width - ft_strlen(str) - negative;
	if (format->plus > -1 && !negative)
		width--;
	if (format->space > -1)
		width--;
	if (width > 0)
	{
		size += width;
		print_spcs(width);
	}
	size += int_non_m_non_z_case(format, negative, width);
	if (i)
	{
		write(1, str, ft_strlen(str));
		size += ft_strlen(str) + negative;
	}
	return (size);
}

int	widths_case_only(t_format *format, char *str, int negative, int i)
{
	int	size;

	size = 0;
	if (format->minus > -1)
		size += minus_case(format, str, negative, i);
	else
	{
		if (format->zero > -1)
			size += non_minus_zero(format, negative, str, i);
		else
			size += non_minus_non_zero(format, negative, str, i);
	}
	free(str);
	return (size);
}
