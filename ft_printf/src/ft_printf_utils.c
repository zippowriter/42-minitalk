/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:27:26 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:33 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_width(t_flag fmt_admin, int count, int *d, int del)
{
	int	diff;

	diff = 0;
	if (fmt_admin.width > count)
	{
		*d += fmt_admin.width - 2;
		diff = fmt_admin.width - count;
		while (diff-- > del)
			ft_putchar_fd(' ', 1);
	}
	else
		*d += count;
}

int	ft_strchr_ascii(const char *s, int c)
{
	char	*str;
	char	cc;

	str = (char *)s;
	cc = (char)c;
	while (*str != '\0')
	{
		if (*str == cc)
			return ((int)cc);
		str++;
	}
	if (cc == '\0')
		return (-1);
	return (-1);
}

void	put_iter_char(char c, int num)
{
	while (num > 0)
	{
		ft_putchar_fd(c, 1);
		num--;
	}
}

void	zero_flag_print(t_flag fmt_admin, int del)
{
	if (fmt_admin.flag[0] == 1 && fmt_admin.prec == -1)
		put_iter_char('0', fmt_admin.width - del);
	else
		put_iter_char(' ', fmt_admin.width - del);
}
