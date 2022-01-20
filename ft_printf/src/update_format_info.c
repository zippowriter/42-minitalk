/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_format_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:58:52 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:29:05 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_width_info(t_flag *fmt_admin, const char **fmt, va_list *ap)
{
	const char	*start;
	char		*ascii_num;

	start = *fmt;
	ascii_num = NULL;
	if (**fmt == '*')
	{
		fmt_admin->width = (int)va_arg(*ap, int);
		if (fmt_admin->width < 0)
		{
			fmt_admin->flag[1] = 1;
			fmt_admin->width *= -1;
		}
		(*fmt)++;
	}
	else if (**fmt >= '0' && **fmt <= '9')
	{
		while (**fmt >= '0' && **fmt <= '9')
			(*fmt)++;
		ascii_num = ft_substr(start, 0, *fmt - start);
		fmt_admin->width = ft_atoi(ascii_num);
		free(ascii_num);
	}
}

void	write_prec_info(t_flag *fmt_admin, const char **fmt, va_list *ap)
{
	const char	*start;
	char		*ascii_num;

	(*fmt)++;
	ascii_num = NULL;
	start = *fmt;
	if (**fmt == '*')
	{
		fmt_admin->prec = (int)va_arg(*ap, int);
		(*fmt)++;
	}
	else if (**fmt >= '0' && **fmt <= '9')
	{
		while (**fmt >= '0' && **fmt <= '9')
			(*fmt)++;
		ascii_num = ft_substr(start, 0, *fmt - start);
		fmt_admin->prec = ft_atoi(ascii_num);
		free(ascii_num);
	}
	else
		fmt_admin->prec = 0;
	if (fmt_admin->prec < -1)
		fmt_admin->prec = -1;
}
