/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:37:04 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/22 20:04:11 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	default_data(t_format *data)
{
	data->type = -1;
	data->hash = -1;
	data->minus = -1;
	data->zero = -1;
	data->plus = -1;
	data->space = -1;
	data->width = -1;
	data->precision = -1;
	data->lenght = -1;
}

static void	fill_prec_wdth_and_spec(char *cutted, t_format *data, size_t i)
{
	if (cutted[i] >= '1' && cutted[i] <= '9' && data->precision == -1
		&& data->width == -1)
		data->width = ft_atoi(&cutted[i]);
	if (cutted[i] == '.' && data->precision == -1)
	{
		data->precision = i;
		i++;
		if (cutted[i] >= '0' && cutted[i] <= '9' && data->lenght == -1)
			data->lenght = ft_atoi(&cutted[i]);
		else
			i--;
	}
	if (included("cspdiuxX%", cutted[i]) && data->type == -1)
		data->type = cutted[i];
}

t_format	*formatted_data(char *cutted)
{
	t_format	*data;
	size_t		i;

	i = 0;
	data = (t_format *)malloc(sizeof(t_format));
	default_data(data);
	while (cutted[i])
	{
		if (cutted[i] == '-' && data->minus == -1)
			data->minus = i;
		if (cutted[i] == '+' && data->plus == -1)
			data->plus = i;
		if (cutted[i] == ' ' && data->space == -1)
			data->space = i;
		if (cutted[i] == '#' && data->hash == -1)
			data->hash = i;
		if (cutted[i] == '0' && data->zero == -1 && data->width == -1)
			data->zero = i;
		if ((cutted[i] == '.' && data->precision >= 0))
			return (NULL);
		fill_prec_wdth_and_spec(cutted, data, i);
		i++;
	}
	return (data);
}
