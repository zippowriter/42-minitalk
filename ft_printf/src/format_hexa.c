/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 08:01:32 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:52:02 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	disc_flags(t_flag fmt_admin, const char *str, int len, int *d)
{
	if (*str == '0' && fmt_admin.prec == 0)
	{
		if (fmt_admin.width > 0)
		{
			put_iter_char(' ', fmt_admin.width);
			*d += fmt_admin.width;
		}
		free((void *)str);
		return ;
	}
	if (fmt_admin.flag[1] == 0)
		not_minus_print_int(fmt_admin, str, len, d);
	else if (fmt_admin.flag[1] == 1)
		is_minus_print_int(fmt_admin, str, len, d);
}

void	print_hexa_lower(t_flag fmt_admin, va_list *ap, int *d)
{
	char			*hexa;
	unsigned int	ui;
	size_t			len;
	int				i;

	ui = (unsigned int)va_arg(*ap, unsigned int);
	hexa = hexa_converter(ui);
	i = 0;
	if (fmt_admin.type == 'X')
	{
		while (hexa[i] != '\0')
		{
			if (hexa[i] >= 'a' && hexa[i] <= 'z')
				hexa[i] -= 32;
			i++;
		}
	}
	len = ft_strlen(hexa);
	disc_flags(fmt_admin, hexa, len, d);
}
