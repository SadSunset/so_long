/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbinary <fbinary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:12:32 by fbinary           #+#    #+#             */
/*   Updated: 2022/06/25 14:12:35 by fbinary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_value_bonus(int n)

{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_len_bonus(int n)

{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa_bonus(int n)

{
	char	*res;
	int		l;

	l = ft_len_bonus(n);
	res = malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		--l;
		res[l] = ft_value_bonus(n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
