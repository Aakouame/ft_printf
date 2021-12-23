/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:53:52 by akouame           #+#    #+#             */
/*   Updated: 2021/12/14 15:17:53 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char a)
{
	write (1, &a, 1);
}

static int	ft_lent(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putnbr(int nb, char *base, int lent)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr((-1) * (nb / lent), base, lent);
		ft_putnbr((-1) * (nb % lent), base, lent);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
		ft_putnbr(nb, base, lent);
	}
	else if (nb < lent)
		ft_putchar(base[nb]);
	else if (nb >= lent)
	{
		ft_putnbr(nb / lent, base, lent);
		ft_putnbr(nb % lent, base, lent);
	}
}

static int	ft_verif(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	lent;
	int	i;

	lent = ft_lent(base);
	if (lent > 1)
	{
		if (ft_verif(base) == 1)
			ft_putnbr(nbr, base, lent);
	}
	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while ((nbr / 10) != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
