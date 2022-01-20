/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 08:16:26 by hkono             #+#    #+#             */
/*   Updated: 2021/11/23 11:51:23 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digits(unsigned int ui)
{
	unsigned int	proxy;
	int				digits;

	proxy = ui;
	digits = 0;
	while (proxy > 0)
	{
		proxy /= 16;
		digits++;
	}
	if (ui == 0)
		return (digits + 1);
	return (digits);
}

char	*hexa_converter(unsigned int ui)
{
	char	*str;
	char	*converter;
	int		digits;
	int		i;

	i = 0;
	digits = get_digits(ui);
	str = (char *)malloc(sizeof(char *) * (digits + 1));
	if (str == NULL)
		return (NULL);
	converter = ft_strdup("0123456789abcdef");
	str[digits] = '\0';
	while (digits > 0)
	{
		i = ui % 16;
		str[--digits] = converter[i];
		ui /= 16;
	}
	free(converter);
	return (str);
}
