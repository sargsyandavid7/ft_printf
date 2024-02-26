/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/02/15 17:34:30 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/15 17:34:30 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += write_spec_data(i++, format, args);
			while (!included("csduixXp%", format[i]) && format[i])
				i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
}
