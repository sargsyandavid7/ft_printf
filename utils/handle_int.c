/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:21:56 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/20 02:22:05 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	handle_simple_int(t_format *format, va_list args_lst)
{
	long	value;
	char	*value_str;
	int		len;

	if (format->type == 'd' || format->type == 'i')
		value = va_arg(args_lst, int);
	if (format->type == 'u')
		value = va_arg(args_lst, unsigned int);
	value_str = ft_itoa(value);
	ft_putstr_fd(value_str, 1);
	len = ft_strlen(value_str);
	free(value_str);
	return (len);
}

int	handle_int(t_format *format_data, va_list args_lst)
{
	if (check_if_simple(format_data))
		return (handle_simple_int(format_data, args_lst));
	return (handle_complex_int(format_data, args_lst));
}
