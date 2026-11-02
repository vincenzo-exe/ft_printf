/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:20:12 by aahmamou          #+#    #+#             */
/*   Updated: 2026/11/02 22:35:04 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr_recursive(long nb)
{
	int	count;
	int	ret;

	count = 0;
	if (nb >= 10)
	{
		ret = putnbr_recursive(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((nb % 10) + '0');
	if (ret == -1)
		return (-1);
	return (count + ret);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		ret;

	nb = n;
	if (nb < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		ret = putnbr_recursive(-nb);
		if (ret == -1)
			return (-1);
		return (ret + 1);
	}
	return (putnbr_recursive(nb));
}