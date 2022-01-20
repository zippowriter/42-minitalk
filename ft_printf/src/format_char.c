/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:41:00 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:52:06 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_flag fmt_admin, va_list *ap, int *d)
{
	char	c;

	c = (char)va_arg(*ap, int);
	*d += 1;
	if (fmt_admin.flag[1] == 1)
	{
		ft_putchar_fd(c, 1);
		if (fmt_admin.width > 0)
		{
			*d += (fmt_admin.width - 1);
			put_iter_char(' ', fmt_admin.width - 1);
		}
	}
	else
	{
		if (fmt_admin.width > 0)
		{
			*d += (fmt_admin.width - 1);
			if (fmt_admin.flag[0] == 1)
				put_iter_char('0', fmt_admin.width - 1);
			else
				put_iter_char(' ', fmt_admin.width - 1);
		}
		ft_putchar_fd(c, 1);
	}
}
