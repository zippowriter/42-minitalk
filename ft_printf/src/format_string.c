/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:58:51 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:44 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_flag fmt_admin, va_list *ap, int *d)
{
	const char	*str;
	size_t		len;
	int			compn;

	str = (char *)va_arg(*ap, char *);
	if (str == NULL)
	{
		free((void *)str);
		str = ft_strdup("(null)");
	}
	len = ft_strlen(str);
	if (fmt_admin.flag[1] == 1)
		is_minus_print(fmt_admin, str, len, d);
	else
		not_minus_print(fmt_admin, str, len, d);
	compn = ft_strncmp(str, "(null)", 6);
	if (compn == 0)
		free((void *)str);
}
