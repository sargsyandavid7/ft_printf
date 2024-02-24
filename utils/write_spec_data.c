/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_spec_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:29:57 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 01:37:51 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_spec_data(int idx, const char *format, va_list args)
{
	int			i;
	char		*cutted;
	t_format	*format_data;

	i = 0;
	format_data = NULL;
	cutted = create_string_spec(idx, format);
	if (!check_cutted(cutted))
	{
		free(cutted);
		return (0);
	}
	format_data = formatted_data(cutted);
	i = create_data_for_print(format_data, args);
	free(cutted);
	free(format_data);
	return (i);
}
