/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:40:30 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/20 01:38:53 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spcs(int size)
{
	char	spc;

	spc = ' ';
	while (size--)
		write(1, &spc, 1);
}

void	print_zeros(int size)
{
	char	zero;

	zero = '0';
	while (size--)
		write(1, &zero, 1);
}
