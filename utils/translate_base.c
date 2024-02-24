/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:24:03 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/24 13:36:12 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_of_hex(unsigned long val)
{
	int	size;

	size = 0;
	while (val > 0)
	{
		val = val / 16;
		size++;
	}
	return (size);
}

char	*translate_to_hex(unsigned long val)
{
	char	*hex_table;
	char	*hex;
	int		size;

	if (val == 0)
		return (ft_strdup("0"));
	hex_table = "0123456789abcdef";
	size = size_of_hex(val);
	hex = (char *)malloc(size + 1);
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (val > 0)
	{
		size--;
		hex[size] = hex_table[val % 16];
		val = val / 16;
	}
	return (hex);
}
