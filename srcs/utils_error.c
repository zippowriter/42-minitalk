/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:51:50 by hkono             #+#    #+#             */
/*   Updated: 2022/01/10 18:44:14 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_handler(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
	return ;
}

void	erro_handler_with_free(char *msg, char *buf)
{
	ft_printf("%s\n", msg);
	free(buf);
	exit(1);
	return ;
}
