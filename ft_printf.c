/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:37:30 by akouame           #+#    #+#             */
/*   Updated: 2021/12/22 15:08:14 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cpt(char *str, int cpt, int i, va_list args)
{
	if (str[i] == '%' && str[i + 1] == 'c')
		cpt = cpt + ft_putchar_fd(((char)va_arg(args, unsigned int)), 1);
	if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		cpt = cpt + ft_putnbr_base(va_arg(args, int), "0123456789");
	if (str[i] == '%' && str[i + 1] == 's')
		cpt = cpt + ft_putstr_fd(va_arg(args, char *), 1);
	if (str[i] == '%' && str[i + 1] == 'u')
		cpt = cpt + ft_u(va_arg(args, unsigned int), "0123456789");
	if (str[i] == '%' && str[i + 1] == 'x')
		cpt = cpt + ft_u(va_arg(args, unsigned int), "0123456789abcdef");
	if (str[i] == '%' && str[i + 1] == 'X')
		cpt = cpt + ft_u(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (str[i] == '%' && str[i + 1] == 'p')
	{
		cpt = cpt + ft_putstr_fd("0x", 1);
		cpt = cpt + ft_p(va_arg(args, unsigned long int), "0123456789abcdef");
	}
	if (str[i] == '%' && str[i + 1] == '%')
	{
		write (1, "\%", 1);
		cpt++;
	}
	return (cpt);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cpt;

	cpt = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_check("cduixp\%Xs", str[i + 1]))
		{
			cpt = ft_cpt((char *)str, cpt, i, args);
			i += 2;
		}
		if (str[i] == '%' && ft_check("cduixp\%Xs", str[i + 1]))
			continue ;
		if (str[i] != '\0' && str[i] != '%')
		{
			write (1, &str[i], 1);
			i++;
			cpt++;
		}
	}
	va_end(args);
	return (cpt);
}
