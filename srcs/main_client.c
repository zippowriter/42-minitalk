/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:47:26 by hkono             #+#    #+#             */
/*   Updated: 2022/01/10 19:51:27 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Handling SIGUSR1\n");
	exit(0);
	return ;
}

void	sigaction_init(struct sigaction *act, sigset_t *mask)
{
	if ((sigemptyset(mask) == -1) || (sigaddset(mask, SIGUSR1) == -1))
		error_handler("sigset error in sigaction_init");
	act->sa_handler = &sig_handler;
	act->sa_mask = *mask;
	act->sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, act, NULL) == -1)
		error_handler("sigaction error in sigaction_init");
	return ;
}

void	send_bit(unsigned char sent_char, pid_t pid)
{
	unsigned char	answer;
	unsigned char	bit;

	bit = 1 << 7;
	while (bit != 0)
	{
		answer = sent_char & bit;
		if (answer == 0)
		{
			if (kill(pid, SIGUSR1) < 0)
				error_handler("kill error in send_bit()");
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				error_handler("kill error in send_bit()");
		}
		if (usleep(100) < 0)
			error_handler("usleep error in send_bit");
		bit >>= 1;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	sigset_t			mask;
	pid_t				pid;
	size_t				i;

	if (argc != 3)
		error_handler("arguments are not adaptive");
	ft_memset(&act, '\0', sizeof(act));
	sigaction_init(&act, &mask);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		error_handler("PID is not sure");
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_bit((unsigned char)argv[2][i], pid);
		i++;
	}
	send_bit('\0', pid);
	pause();
	return (0);
}
