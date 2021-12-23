/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:24:58 by akouame           #+#    #+#             */
/*   Updated: 2021/12/14 15:18:45 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

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

static void	ft_putnbr(unsigned int nb, char *base, unsigned int lent)
{
	if (nb < lent)
		ft_putchar(base[nb]);
	if (nb >= lent)
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

int	ft_u(unsigned int nbr, char *base)
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
	while ((nbr / lent) != 0)
	{
		nbr = nbr / lent;
		i++;
	}
	return (i);
}
