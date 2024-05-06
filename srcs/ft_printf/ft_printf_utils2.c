/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:09:15 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:35:26 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putchar(char c)
{
	int		i;

	i = write(1, &c, 1);
	(void)i;
	return (1);
}

int	ft_putunsnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + 48);
	}
	else
	{
		i += ft_putchar(n + 48);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;
	int	j;

	i = 0;
	if (n == -2147483648)
	{
		j = write(1, "-2147483648", 11);
		(void)j;
		return (11);
	}
	if (n < 0)
	{
		j = write(1, "-", 1);
		i++;
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + 48);
	}
	else
		i += ft_putchar(n + 48);
	(void)j;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
	{
		i = write(1, "(null)", 6);
		(void)i;
		return (6);
	}
	while (str[i])
	{
		j = write(1, &str[i], 1);
		i++;
	}
	(void)j;
	return (i);
}
