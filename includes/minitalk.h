/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:21:13 by hkono             #+#    #+#             */
/*   Updated: 2022/01/10 18:43:56 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

# define BUF_SIZE 10

typedef struct s_signal
{
	volatile int	sig;
	volatile pid_t	pid;
}	t_signal;

void	error_handler(char *msg);
void	erro_handler_with_free(char *msg, char *buf);
void	recieve_signal(char **buf, size_t *buf_size, int signal, pid_t pid);
int		buf_init(char **buf, size_t *buf_size);
char	*buf_resize(char *buf, size_t buf_size);

#endif
