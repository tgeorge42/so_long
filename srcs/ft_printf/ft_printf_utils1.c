/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:27:02 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:33:29 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_put_ptr(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_put_ptr(ptr / 16);
		i += ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			i += ft_putchar(ptr + 48);
		else
			i += ft_putchar(ptr - 10 + 'a');
	}
	return (i);
}

int	ft_putadress(unsigned long long ptr)
{
	int	i;

	if (!ptr)
	{
		i = write(1, "(nil)", 5);
		(void)i;
		return (5);
	}
	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
		i += ft_put_ptr(ptr);
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	long	nb;
	int		i;
	int		j;

	i = 0;
	nb = nbr;
	if (nb >= 16)
	{
		i += ft_putnbr_base(nb / 16, base);
		i += ft_putnbr_base(nb % 16, base);
	}
	else
	{
		j = write(1, &base[nb % 16], 1);
		i++;
	}
	(void)j;
	return (i);
}

int	ft_put_hexamin(int nbr)
{
	int	i;

	i = 0;
	i += ft_putnbr_base(nbr, "0123456789abcdef");
	return (i);
}

int	ft_put_hexamaj(int nbr)
{
	int	i;

	i = 0;
	i += ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (i);
}
