/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:34:51 by akouame           #+#    #+#             */
/*   Updated: 2021/12/14 18:02:52 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr_base(int nbr, char *base);
int		ft_check(char *str, char c);
int		ft_u(unsigned int nbr, char *base);
int		ft_p(unsigned long int nbr, char *base);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);

#endif
