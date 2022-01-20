/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minus_print_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:57:16 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:10 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ws_negative_n(t_flag fmt_admin, const char *str, int len, int *d)
{
	ft_putchar_fd('-', 1);
	str++;
	len--;
	put_iter_char('0', fmt_admin.prec - len);
	ft_putstr_fd((char *)str, 1);
	if (fmt_admin.prec > len)
		*d += fmt_admin.prec + 1;
	else
		*d += len + 1;
}

static void	wl_negative_n(t_flag fmt_admin, const char *str, int len)
{
	ft_putchar_fd('-', 1);
	str++;
	len--;
	put_iter_char('0', fmt_admin.prec - len);
	ft_putstr_fd((char *)str, 1);
	if (fmt_admin.prec > len)
		put_iter_char(' ', fmt_admin.width - 1 - fmt_admin.prec);
	else
		put_iter_char(' ', fmt_admin.width - 1 - len);
}

static void	width_short(t_flag fmt_admin, const char *str, int len, int *d)
{
	if (fmt_admin.prec > len)
	{
		if (*str == '-')
			ws_negative_n(fmt_admin, str, len, d);
		else
		{
			put_iter_char('0', fmt_admin.prec - len);
			ft_putstr_fd((char *)str, 1);
			*d += fmt_admin.prec;
		}
	}
	else
	{
		if (*str == '-')
			ws_negative_n(fmt_admin, str, len, d);
		else
		{
			ft_putstr_fd((char *)str, 1);
			*d += len;
		}
	}
}

static void	width_long(t_flag fmt_admin, const char *str, int len)
{
	if (fmt_admin.prec > len)
	{
		if (*str == '-')
			wl_negative_n(fmt_admin, str, len);
		else
		{
			put_iter_char('0', fmt_admin.prec - len);
			ft_putstr_fd((char *)str, 1);
			put_iter_char(' ', fmt_admin.width - fmt_admin.prec);
		}
	}
	else
	{
		if (*str == '-')
			wl_negative_n(fmt_admin, str, len);
		else
		{
			ft_putstr_fd((char *)str, 1);
			put_iter_char(' ', fmt_admin.width - len);
		}
	}
}

void	is_minus_print_int(t_flag fmt_admin, const char *str, int len, int *d)
{
	if (fmt_admin.width > len && fmt_admin.width > fmt_admin.prec)
	{
		*d += fmt_admin.width;
		width_long(fmt_admin, str, len);
	}
	else
		width_short(fmt_admin, str, len, d);
	free((void *)str);
}
