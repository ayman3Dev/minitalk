/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:38:02 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/19 22:48:49 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
#include <sys/time.h>

void	send(int pid, char *message)
{
	int	m;
	int	i;
	int	p;
	int	n;

	m = 0;
	i = 0;
	while (message[m] != '\0')
	{
		p = 7;
		i = 0;
		while (i < 8)
		{
			if ((message[m] >> p & 1) == 1)
				kill(pid, SIGUSR2);
			else if ((message[m] >> p & 1) == 0)
				kill(pid, SIGUSR1);
			usleep(900);
			p--;
			i++;
		}
		m++;
	}
	p = 7;
	n = '\n';
	i = 0;
	while (i < 8)
	{
		if ((n >> p & 1) == 1)
			kill(pid, SIGUSR2);
		else if ((n >> p & 1) == 0)
			kill(pid, SIGUSR1);
		usleep(900);
		p--;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	s_pid;

	if(argc != 3)
		return (1);
	s_pid = ft_atoi(argv[1]);
	if (s_pid == 0)
		return (0);
	printf("%d", s_pid);
	send(s_pid, argv[2]);
}
