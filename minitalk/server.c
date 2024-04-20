/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:52:10 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/20 22:24:04 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	a;
	static int	i;
	static int	pid;

	(void)context;
	if (pid == 0)
		pid = siginfo->si_pid;
	else if (siginfo->si_pid != pid)
	{
		a = 0;
		i = 0;
		pid = siginfo->si_pid;
	}
	if (signum == SIGUSR2)
		i = (i << 1) | 1;
	else if (signum == SIGUSR1)
		i = (i << 1) | 0;
	a++;
	if (a == 8)
	{
		ft_putchar(i);
		a = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putdec(getpid());
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
}
