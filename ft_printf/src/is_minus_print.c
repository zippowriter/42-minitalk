/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minus_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:25:10 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:17 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prec_zero(t_flag fmt_admin, int *d)
{
	if (fmt_admin.width > 0)
	{
		put_iter_char(' ', fmt_admin.width);
		*d += fmt_admin.width;
	}
}

static void	width_long(t_flag fmt_admin, const char *str, int len, char c)
{
	int	i;

	i = 0;
	if (fmt_admin.prec < len && fmt_admin.prec != -1)
	{
		while (fmt_admin.prec - i++ > 0)
			ft_putchar_fd((char)*str++, 1);
		put_iter_char(c, fmt_admin.width - fmt_admin.prec);
	}
	else
	{
		ft_putstr_fd((char *)str, 1);
		put_iter_char(c, fmt_admin.width - len);
	}
}

void	is_minus_print(t_flag fmt_admin, const char *str, int len, int *d)
{
	int	i;

	i = 0;
	if (fmt_admin.width > len \
		|| (fmt_admin.width > fmt_admin.prec && fmt_admin.prec != -1))
	{
		*d += fmt_admin.width;
		width_long(fmt_admin, str, len, ' ');
	}
	else
	{
		if (fmt_admin.prec == 0)
			prec_zero(fmt_admin, d);
		else if (fmt_admin.prec < len && fmt_admin.prec != -1)
		{
			*d += fmt_admin.prec;
			while (fmt_admin.prec - i++ > 0)
				ft_putchar_fd((char)*str++, 1);
		}
		else
		{
			*d += len;
			ft_putstr_fd((char *)str, 1);
		}
	}
}
