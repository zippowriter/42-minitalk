/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:06:23 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:31:59 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(t_flag fmt_admin, va_list *ap, int *d)
{
	if (fmt_admin.type == 'c')
		print_char(fmt_admin, ap, d);
	if (fmt_admin.type == 'p')
		print_address(fmt_admin, ap, d);
	if (fmt_admin.type == 's')
		print_string(fmt_admin, ap, d);
	if (fmt_admin.type == 'd' || fmt_admin.type == 'i')
		print_integer(fmt_admin, ap, d);
	if (fmt_admin.type == 'u')
		print_unsigned(fmt_admin, ap, d);
	if (fmt_admin.type == 'x' || fmt_admin.type == 'X')
		print_hexa_lower(fmt_admin, ap, d);
	if (fmt_admin.type == '%')
		print_percent(fmt_admin, d);
}
