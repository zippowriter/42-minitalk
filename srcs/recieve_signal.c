/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recieve_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:28:51 by hkono             #+#    #+#             */
/*   Updated: 2022/01/10 18:44:13 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_to_bit(unsigned char *uc, int signal)
{
	if (signal == SIGUSR1)
		*uc |= 0;
	else if (signal == SIGUSR2)
		*uc |= 1;
	return ;
}

void	recieve_stop(char *buf, size_t buf_size, pid_t pid, size_t *i)
{
	ft_printf("%s\n", buf);
	if (usleep(100) < 0)
		erro_handler_with_free("usleep error in recieve_stop()", buf);
	if (kill(pid, SIGUSR1) < 0)
		erro_handler_with_free("kill error in recieve_stop()", buf);
	ft_memset(buf, '\0', buf_size);
	*i = 0;
	return ;
}

void	resize_buf(char **buf, size_t *buf_size)
{
	*buf = buf_resize(*buf, *buf_size);
	if (*buf == NULL)
		error_handler("buf_resize error in resize_buf");
	*buf_size *= 2;
	return ;
}

void	recieve_signal(char **buf, size_t *buf_size, int signal, pid_t pid)
{
	static unsigned char	uc;
	static size_t			count;
	static size_t			i;

	signal_to_bit(&uc, signal);
	if (count == 7)
	{
		(*buf)[i] = (char)uc;
		if ((*buf)[i] == '\0')
			recieve_stop(*buf, *buf_size, pid, &i);
		else
		{
			if (i == *buf_size - 1)
				resize_buf(buf, buf_size);
			i++;
		}
		uc = 0;
		count = 0;
		return ;
	}
	uc <<= 1;
	count++;
	return ;
}
