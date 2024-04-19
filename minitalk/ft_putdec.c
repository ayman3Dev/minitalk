/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:38:24 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/19 15:41:27 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_lendec(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = n * -1;
		len = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putdec(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		ft_putdec(n);
	}
	else if (n > 9)
	{
		ft_putdec(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else
		ft_putchar(n + 48);
	return (ft_lendec(n) + len);
}
