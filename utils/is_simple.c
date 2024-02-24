/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:59:03 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/17 20:03:27 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
