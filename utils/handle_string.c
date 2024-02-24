/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:25:17 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/18 00:40:19 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_simple_string(va_list argslist)
{
	char	*string;

	string = va_arg(argslist, char *);
	if (string == NULL)
		string = "(null)";
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	handle_string(t_format *format, va_list argslst)
{
	if (check_if_simple(format))
		return (handle_simple_string(argslst));
	return (handle_complex_string(format, argslst));
}
