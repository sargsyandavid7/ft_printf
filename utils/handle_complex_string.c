/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_complex_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:17:27 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/20 01:09:26 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case1(t_format *format, int *size, char *string)
{
	if (string == NULL)
	{
		string = "(null)";
		if (format->lenght < 6)
			return (0);
	}
	if (format->width > format->lenght)
	{
		if (format->minus == -1)
			print_spcs(format->width - format->lenght);
		write(1, string, format->lenght);
		if (format->minus != -1)
			print_spcs(format->width - format->lenght);
		*size += format->width;
	}
	else
	{
		write(1, string, format->lenght);
		*size = format->lenght;
	}
	return (*size);
}

static int	case2(t_format *format, int *size, char *string)
{
	int	len;

	if (string == NULL)
	{
		string = "(null)";
		if (format->lenght < 6)
			return (0);
	}
	len = ft_strlen(string);
	if (format->width > len)
	{
		if (format->minus == -1)
			print_spcs(format->width - len);
		write(1, string, len);
		if (format->minus != -1)
			print_spcs(format->width - len);
		*size = format->width;
	}
	else
	{
		write(1, string, len);
		*size = len;
	}
	return (*size);
}

static int	case3(t_format *format, int *size, char *string)
{
	int	len;

	if (string == NULL)
		string = "(null)";
	len = ft_strlen(string);
	if (format->minus == -1 && format->width > len)
		print_spcs(format->width - len);
	write(1, string, len);
	if (format->minus != -1 && format->width > len)
		print_spcs(format->width - len);
	if (format->width > len)
		*size = format->width;
	else
		*size = len;
	return (*size);
}

int	handle_complex_string(t_format *format, va_list argslist)
{
	char	*string;
	int		len;
	int		size;

	string = va_arg(argslist, char *);
	size = 0;
	len = ft_strlen(string);
	if (format->precision > -1 && format->lenght == -1)
		format->lenght = 0;
	if (format->lenght <= len && format->lenght != -1)
		return (case1(format, &size, string));
	else if (format->lenght > len)
		return (case2(format, &size, string));
	else if (format->lenght == -1 && format->width > len)
		return (case3(format, &size, string));
	else if (format->lenght < len && format->width <= len)
	{
		if (string == NULL)
			string = "(null)";
		len = ft_strlen(string);
		size += len;
		write(1, string, len);
	}
	return (size);
}
