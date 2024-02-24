/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:31:37 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/22 18:35:33 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_logic(int negative, t_format *format, int width, int size)
{
	if (negative)
		write(1, "-", 1);
	if (format->plus > -1 && !negative)
	{
		write(1, "+", 1);
		if (width-- != 0)
			size++;
	}
	if (format->space > -1 && !negative)
	{
		if (width-- != 0)
			size++;
		write(1, " ", 1);
	}
	return (size);
}
