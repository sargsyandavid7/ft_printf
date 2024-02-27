/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:41:20 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/27 09:05:25 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		a = (char *)malloc(1 * sizeof(char));
		a[0] = '\0';
		return (a);
	}
	if (len > ft_strlen(s) - start)
		a = (char *)malloc(ft_strlen(s) - start + 1);
	else
		a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[i + start])
	{
		a[i] = s[i + start];
		i++;
	}
	a[i] = '\0';
	return (a);
}
