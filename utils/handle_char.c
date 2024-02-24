/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:59:43 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/17 22:51:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	handle_simple_char(va_list args_lst)
{
	int	value;

	value = va_arg(args_lst, int);
	write(1, &value, 1);
	return (1);
}

static int	handle_complex_char(t_format *formatted_data, va_list args_lst)
{
	int		val;
	int		len;

	val = va_arg(args_lst, int);
	len = formatted_data->width;
	if (formatted_data->width > 1)
	{
		if (formatted_data->minus >= 0)
		{
			write(1, &val, 1);
			while (formatted_data->width-- > 1)
				write(1, " ", 1);
		}
		else
		{
			while (formatted_data->width-- > 1)
				write(1, " ", 1);
			write(1, &val, 1);
		}
	}
	else
		len = write(1, &val, 1);
	return (len);
}

int	check_if_simple(t_format *formatted_data)
{
	if (formatted_data->width != -1)
		return (0);
	if (formatted_data->zero != -1)
		return (0);
	if (formatted_data->minus != -1)
		return (0);
	if (formatted_data->precision != -1)
		return (0);
	if (formatted_data->lenght != -1)
		return (0);
	if (formatted_data->hash != -1)
		return (0);
	if (formatted_data->plus != -1)
		return (0);
	if (formatted_data->space != -1)
		return (0);
	return (1);
}

int	handle_char(t_format *formatted_data, va_list args_lst)
{
	if (check_if_simple(formatted_data))
		return (handle_simple_char(args_lst));
	else
		return (handle_complex_char(formatted_data, args_lst));
	return (0);
}
