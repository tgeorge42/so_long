/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:15:57 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/24 16:38:06 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_nbchar(int n)
{
	int	nb;

	nb = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		nb = 1;
		n = -n;
	}
	while (n / 10 > 0)
	{
		nb++;
		n = n / 10;
	}
	nb++;
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		end;
	long	nb;

	end = 0;
	nb = n;
	i = ft_nbchar(nb);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
		end = 1;
	}
	res[i] = '\0';
	while (i-- > end)
	{
		res[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}
