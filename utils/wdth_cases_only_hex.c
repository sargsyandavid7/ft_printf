/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdth_cases_only_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:50:51 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/19 17:54:11 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_logic_hex(t_format *format, int width, int size)
{
	if (format->hash > -1)
	{
		if (width == 1)
		{
			width -= 1;
			size += 2;
		}
		else if (width == 0)
			size += 2;
		else if (width > 1)
		{
			size += 2;
			width -= 2;
		}
		if (format->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	return (size);
}

static int	minus_case(t_format *format, char *str, int i)
{
	int	size;
	int	width;

	size = 0;
	width = format->width - ft_strlen(str);
	if (str[0] != '0' || format->type == 'p')
		size += print_logic_hex(format, width, size);
	if (format->hash > -1 && (str[0] != '0' || format->type == 'p'))
	{
		if (width > 1)
			width -= 2;
		else if (width == 1)
			width -= 1;
	}
	if (i)
	{
		write(1, str, ft_strlen(str));
		size += ft_strlen(str);
	}
	if (width > 0)
	{
		size += width;
		print_spcs(width);
	}
	return (size);
}

static int	non_minus_zero(t_format *format, char *str, int i)
{
	int	size;
	int	width;

	size = 0;
	width = format->width - ft_strlen(str);
	if (str[0] != '0' || format->type == 'p')
		size += print_logic_hex(format, width, size);
	if (format->hash > -1 && (str[0] != '0' || format->type == 'p'))
	{
		if (width > 1)
			width -= 2;
		else if (width == 1)
			width -= 1;
	}
	if (width > 0)
	{
		size += width;
		print_zeros(width);
	}
	if (i)
	{
		write(1, str, ft_strlen(str));
		size += ft_strlen(str);
	}
	return (size);
}

static int	non_minus_non_zero(t_format *format, char *str, int i)
{
	int	size;
	int	width;

	size = 0;
	width = format->width - ft_strlen(str);
	if (format->hash > -1 && (str[0] != '0' || format->type == 'p'))
	{
		if (width > 1)
			width -= 2;
		else if (width == 1)
			width -= 1;
	}
	if (width > 0)
	{
		size += width;
		print_spcs(width);
	}
	if (str[0] != '0' || format->type == 'p')
		size = print_logic_hex(format, width, size);
	if (i)
	{
		write(1, str, ft_strlen(str));
		size += ft_strlen(str);
	}
	return (size);
}

int	widths_case_only_hex(t_format *format, char *str, int i)
{
	int	size;

	size = 0;
	if (format->minus > -1)
		size += minus_case(format, str, i);
	else
	{
		if (format->zero > -1)
			size += non_minus_zero(format, str, i);
		else
			size += non_minus_non_zero(format, str, i);
	}
	free(str);
	return (size);
}
