/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:51:37 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:29 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digits(unsigned int ui)
{
	int				digits;
	unsigned int	proxy;

	proxy = ui;
	digits = 0;
	while (proxy > 0)
	{
		proxy /= 10;
		digits++;
	}
	if (ui == 0)
		digits++;
	return (digits);
}

char	*ft_utoa(unsigned int ui)
{
	char			*str;
	int				digits;

	digits = get_digits(ui);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[--digits] = (ui % 10) + '0';
		ui /= 10;
	}
	return (str);
}
