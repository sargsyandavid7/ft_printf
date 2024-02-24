/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:14:32 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 01:47:56 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

int	handle_simple_hex(t_format *format, va_list args_lst)
{
	unsigned int	value;
	char			*hex_str;
	int				len;

	value = va_arg(args_lst, unsigned int);
	hex_str = translate_to_hex(value);
	if (format->type == 'X')
		ft_strtoupper(hex_str);
	write(1, hex_str, ft_strlen(hex_str));
	len = ft_strlen(hex_str);
	free(hex_str);
	return (len);
}

int	handle_hex(t_format *format, va_list args_lst)
{
	if (check_if_simple(format))
		return (handle_simple_hex(format, args_lst));
	return (handle_complex_hex(format, args_lst));
}
