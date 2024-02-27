/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:34:54 by dasargsy          #+#    #+#             */
/*   Updated: 2024/02/15 17:34:54 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_format
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	type;
	int		lenght;

}	t_format;

int			ft_printf(const char *format, ...);
int			included(const char *s, char c);
int			write_spec_data(int idx, const char *format, va_list args);
char		*create_string_spec(int index, const char *format);
int			check_cutted(char *cutted);
t_format	*formatted_data(char *cutted);
int			create_data_for_print(t_format *formatted_data, va_list args_lst);
int			handle_char(t_format *format, va_list args_lst);
int			check_if_simple(t_format *formatted_data);
int			handle_string(t_format *format, va_list argslst);
int			handle_complex_string(t_format *format, va_list argslist);
void		print_spcs(int size);
int			handle_int(t_format *format, va_list args_lst);	
int			handle_complex_int(t_format *format, va_list args_lst);
void		print_zeros(int size);
int			simple_prec_case(t_format *format, char *str, int negative, int i);
int			wdths_and_prec_case(t_format *format, char *str, int negative);
int			widths_case_only(t_format *format, char *str, int negative, int i);
int			print_logic(int negative, t_format *format, int width, int size);
int			handle_hex(t_format *format, va_list args_lst);
char		*translate_to_hex(unsigned long val);
int			normal_case_hex(t_format *format, char *str);
int			handle_complex_hex(t_format *format, va_list args_lst);
int			widths_case_only_hex(t_format *format, char *str, int i);
int			simple_prec_case_hex(t_format *format, char *str, int i);
int			wdths_and_prec_case_hex(t_format *format, char *str);
int			handle_pointer(t_format *format, va_list args_lst);
int			handle_percent(void);
int			ft_atoi(const char *str);
char		*ft_strdup(char const *str);
size_t		ft_strlen(char const *str);
char		*ft_itoa(long nb);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

#endif