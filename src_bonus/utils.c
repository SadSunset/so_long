/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbinary <fbinary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:16:41 by fbinary           #+#    #+#             */
/*   Updated: 2022/06/25 14:16:43 by fbinary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putnbr_bonus(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_bonus(n / 10);
		ft_putnbr_bonus(n % 10);
	}
}

void	ft_putstr_bonus(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	fd_open_bonus(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Fd no valid \n", 14);
		exit (0);
	}
	return (fd);
}
