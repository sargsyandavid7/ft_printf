/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:16:39 by dasargsy          #+#    #+#             */
/*   Updated: 2024/03/19 17:57:16 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_percent(t_format *format)
{
	if (check_if_simple(format))
	{
		write(1, "%", 1);
		return (1);
	}
	return (widths_case_only(format, ft_strdup("%"), 0, 1));
}
