/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:38:02 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/20 18:36:18 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_newline(char c, int pid)
{
	int	p;
	int	i;

	p = 7;
	i = 0;
	while (i < 8)
	{
		if ((c >> p & 1) == 1)
			kill(pid, SIGUSR2);
		else if ((c >> p & 1) == 0)
			kill(pid, SIGUSR1);
		usleep(960);
		p--;
		i++;
	}
}

void	send(int pid, char *message)
{
	int	m;
	int	i;
	int	p;

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
			usleep(960);
			p--;
			i++;
		}
		m++;
	}
	ft_print_newline('\n', pid);
}

int	main(int argc, char **argv)
{
	int	s_pid;

	if (argc != 3)
		return (1);
	s_pid = ft_atoi(argv[1]);
	if (s_pid == 0)
		return (0);
	printf("%d", s_pid);
	send(s_pid, argv[2]);
	return (0);
}
