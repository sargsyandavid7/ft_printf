/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_for_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:04:34 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 23:17:46 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	create_data_for_print(t_format *formatted_data, va_list args_lst)
{
	int	value_len;

	if (formatted_data->type == 'c')
		value_len = handle_char(formatted_data, args_lst);
	if (formatted_data->type == 's')
		value_len = handle_string(formatted_data, args_lst);
	if (formatted_data->type == 'd' || formatted_data->type == 'i'
		|| formatted_data->type == 'u')
		value_len = handle_int(formatted_data, args_lst);
	if (formatted_data->type == 'x' || formatted_data->type == 'X')
		value_len = handle_hex(formatted_data, args_lst);
	if (formatted_data->type == 'p')
		value_len = handle_pointer(formatted_data, args_lst);
	if (formatted_data->type == '%')
		value_len = handle_percent();
	return (value_len);
}
