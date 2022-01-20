/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:18:39 by hkono             #+#    #+#             */
/*   Updated: 2022/01/10 20:09:16 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile t_signal	g_signal;

void	sig_handler(int signal, siginfo_t *info, void *ucontext)
{
	(void)*ucontext;
	g_signal.sig = signal;
	g_signal.pid = info->si_pid;
	return ;
}

void	set_signal(struct sigaction *act, sigset_t *mask)
{
	if ((sigemptyset(mask) == -1) || \
		(sigaddset(mask, SIGUSR1) == -1) || \
		(sigaddset(mask, SIGUSR2) == -1))
		error_handler("sigset error in set_signal()");
	act->sa_sigaction = &sig_handler;
	act->sa_mask = *mask;
	act->sa_flags = SA_SIGINFO | SA_RESTART;
	if ((sigaction(SIGUSR1, act, NULL) == -1) || \
		(sigaction(SIGUSR2, act, NULL) == -1) || \
		(sigaction(SIGQUIT, act, NULL) == -1) || \
		(sigaction(SIGINT, act, NULL) == -1))
		error_handler("sigaction error in set_signal()");
	return ;
}

void	main_loop(char **buf, size_t *buf_size)
{
	while (1)
	{
		if (g_signal.sig == SIGUSR1 || g_signal.sig == SIGUSR2)
			recieve_signal(buf, buf_size, g_signal.sig, g_signal.pid);
		if (g_signal.sig == SIGQUIT || g_signal.sig == SIGINT)
			break ;
		pause();
	}
	return ;
}

int	main(void)
{
	struct sigaction	act;
	sigset_t			mask;
	char				*buf;
	size_t				buf_size;

	ft_memset(&act, '\0', sizeof(act));
	set_signal(&act, &mask);
	ft_printf("PID: %d\n", getpid());
	if (!buf_init(&buf, &buf_size))
		error_handler("buf_init error in main");
	main_loop(&buf, &buf_size);
	free(buf);
	return (0);
}
