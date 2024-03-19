/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:31:37 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/19 14:39:36 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_logic(int negative, t_format *format, int *width, int size)
{
	if (format->space > -1 && negative == 0)
	{
		if ((*width)-- != -1)
			size++;
		write(1, " ", 1);
	}
	if (negative)
		write(1, "-", 1);
	if (format->plus > -1 && !negative)
	{
		write(1, "+", 1);
		if ((*width)-- != -1)
			size++;
	}
	return (size);
}
