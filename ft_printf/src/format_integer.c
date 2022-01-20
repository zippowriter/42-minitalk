/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:50:57 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:58 by hkono            ###   ########.fr       */
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
	else if (fmt_admin.flag[1] == 0)
		not_minus_print_int(fmt_admin, str, len, d);
	else if (fmt_admin.flag[1] == 1)
		is_minus_print_int(fmt_admin, str, len, d);
}

void	print_integer(t_flag fmt_admin, va_list *ap, int *d)
{
	char	*str;
	char	*itoa;
	int		num;
	size_t	len;

	num = (int)va_arg(*ap, int);
	itoa = ft_itoa(num);
	str = ft_strdup(itoa);
	len = ft_strlen(str);
	disc_flags(fmt_admin, str, len, d);
	free(itoa);
}
