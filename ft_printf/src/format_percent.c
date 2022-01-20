/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:12:37 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:54 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_flag fmt_admin, int *d)
{
	*d += 1;
	if (fmt_admin.flag[1] == 1)
	{
		ft_putchar_fd('%', 1);
		if (fmt_admin.width > 0)
		{
			*d += fmt_admin.width - 1;
			put_iter_char(' ', fmt_admin.width - 1);
		}
	}
	else
	{
		if (fmt_admin.width > 0)
		{
			*d += fmt_admin.width - 1;
			if (fmt_admin.flag[0] == 1)
				put_iter_char('0', fmt_admin.width - 1);
			else
				put_iter_char(' ', fmt_admin.width - 1);
		}
		ft_putchar_fd('%', 1);
	}
}
