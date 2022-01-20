/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:09:22 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:52:49 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

typedef struct s_flag
{
	int	flag[2];
	int	width;
	int	prec;
	int	type;
}	t_flag;

int		ft_printf(const char *fmt, ...);
void	write_width_info(t_flag *fmt_admin, const char **fmt, va_list *ap);
void	write_prec_info(t_flag *fmt_admin, const char **fmt, va_list *ap);
int		ft_strchr_ascii(const char *s, int c);
void	print_space_width(t_flag fmt_admin, int count, int *d, int del);
void	put_iter_char(char c, int num);
void	zero_flag_print(t_flag fmt_admin, int del);
char	*hexa_converter(unsigned int ui);
char	*ft_utoa(unsigned int ui);
void	print_format(t_flag fmt_admin, va_list *ap, int *d);
void	print_char(t_flag fmt_admin, va_list *ap, int *d);
void	print_address(t_flag fmt_admin, va_list *ap, int *d);
void	print_string(t_flag fmt_admin, va_list *ap, int *d);
void	print_integer(t_flag fmt_admin, va_list *ap, int *d);
void	print_unsigned(t_flag fmt_admin, va_list *ap, int *d);
void	print_hexa_lower(t_flag fmt_admin, va_list *ap, int *d);
void	print_percent(t_flag fmt_admin, int *d);
void	is_minus_print(t_flag fmt_admin, const char *str, int len, int *d);
void	not_minus_print(t_flag fmt_admin, const char *str, int len, int *d);
void	is_minus_print_int(t_flag fmt_admin, const char *str, int len, int *d);
void	not_minus_print_int(t_flag fmt_admin, const char *str, int len, int *d);

#endif
