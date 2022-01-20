/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:54:30 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:37 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_admin_init(t_flag *fmt_admin)
{
	fmt_admin->flag[0] = 0;
	fmt_admin->flag[1] = 0;
	fmt_admin->width = -1;
	fmt_admin->prec = -1;
	fmt_admin->type = -1;
}

static int	do_prcnt(const char **fmt, int *d, va_list *ap)
{
	t_flag	fmt_admin;

	(*fmt)++;
	format_admin_init(&fmt_admin);
	if (**fmt == '0')
	{
		fmt_admin.flag[0] = 1;
		(*fmt)++;
	}
	if (**fmt == '-')
	{
		fmt_admin.flag[1] = 1;
		(*fmt)++;
	}
	write_width_info(&fmt_admin, fmt, ap);
	if (fmt_admin.width == INT_MIN || fmt_admin.width == INT_MAX)
		return (-1);
	if (**fmt == '.')
		write_prec_info(&fmt_admin, fmt, ap);
	fmt_admin.type = ft_strchr_ascii("cspdiuxX%", **fmt);
	(*fmt)++;
	print_format(fmt_admin, ap, d);
	return (1);
}

static void	do_other(const char **start, const char **fmt, int *d)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*d += *fmt - *start;
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			d;
	const char	*start;

	d = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		d = -1;
	while (d >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
			do_other(&start, &fmt, &d);
		else
			if (do_prcnt(&fmt, &d, &ap) == -1)
				return (-1);
	}
	va_end(ap);
	return (d);
}
