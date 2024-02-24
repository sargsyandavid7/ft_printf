/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string_spec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:35:04 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/15 21:54:04 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*create_string_spec(int index, const char *format)
{
	int		i;
	char	*cutted;

	i = 1;
	cutted = NULL;
	while (!included("csduixXp%", format[index + i]) && format[i + index])
		i++;
	cutted = ft_substr((char *)format, index + 1, i);
	return (cutted);
}
