/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:42:43 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 13:03:08 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	no_minus_print(t_flag fmt_admin, char *ad, int len, int *d)
{
	if (fmt_admin.width > len + 2)
	{
		put_iter_char(' ', fmt_admin.width - len - 2);
		ft_putstr_fd("0x", 1);
		if (!(*ad == '0' && fmt_admin.prec == 0))
			ft_putstr_fd(ad, 1);
		*d += (fmt_admin.width - 2);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		if (!(*ad == '0' && fmt_admin.prec == 0))
			ft_putstr_fd(ad, 1);
		*d += len;
	}
}

static void	minus_flag_print(t_flag fmt_admin, char *ad, int len, int *d)
{
	if (fmt_admin.width > len + 2)
	{
		if (!(*ad == '0' && fmt_admin.prec == 0))
			ft_putstr_fd(ad, 1);
		put_iter_char(' ', fmt_admin.width - len - 2);
		*d += (fmt_admin.width - 2);
	}
	else
	{
		if (!(*ad == '0' && fmt_admin.prec == 0))
			ft_putstr_fd(ad, 1);
		*d += len;
	}
}

static int	get_digits(unsigned long long ull)
{
	unsigned long long	proxy;
	int					digits;

	proxy = ull;
	digits = 0;
	while (proxy > 0)
	{
		proxy /= 16;
		digits++;
	}
	if (ull == 0)
		digits++;
	return (digits);
}

static char	*convert_address(unsigned long long ull)
{
	char	*str;
	char	*converter;
	int		digits;
	int		i;

	i = 0;
	digits = get_digits(ull);
	str = (char *)malloc(sizeof(char *) * (digits + 1));
	if (str == NULL)
		return (NULL);
	converter = ft_strdup("0123456789abcdef");
	str[digits] = '\0';
	while (digits > 0)
	{
		i = ull % 16;
		str[--digits] = converter[i];
		ull /= 16;
	}
	free(converter);
	return (str);
}

void	print_address(t_flag fmt_admin, va_list *ap, int *d)
{
	char				*ad;
	unsigned long long	ull;
	size_t				len;

	ull = (unsigned long long)va_arg(*ap, unsigned long long);
	ad = convert_address(ull);
	len = ft_strlen(ad);
	if (*ad == '0' && fmt_admin.prec == 0)
		len--;
	if (fmt_admin.flag[1] == 1)
	{
		ft_putstr_fd("0x", 1);
		*d += 2;
		minus_flag_print(fmt_admin, ad, len, d);
	}
	else
	{
		*d += 2;
		no_minus_print(fmt_admin, ad, len, d);
	}
	free(ad);
}
