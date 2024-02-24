/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cutted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:57:11 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/23 01:37:31 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_by_symbols(char *cutted)
{
	int	i;

	i = 0;
	while (cutted[i])
	{
		if (!included("+-0# .csduixXp%", cutted[i])
			&& !ft_isdigit(cutted[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_order(char *cutted)
{
	int	i;
	int	precision;

	i = 0;
	precision = -1;
	while (cutted[i])
	{
		if (cutted[i] == '.')
			precision = i;
		if (included("+- ", cutted[i]) && (precision != -1) && i > precision)
			return (0);
		i++;
	}
	return (1);
}

int	check_cutted(char *cutted)
{
	return (check_by_symbols(cutted) && check_order(cutted));
}
