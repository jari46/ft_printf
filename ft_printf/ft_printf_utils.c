/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:52:33 by yehan             #+#    #+#             */
/*   Updated: 2022/03/28 16:56:47 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putarg_cnt(va_list *ap, char type)
{
	int			cnt;

	cnt = 0;
	if (type == '%')
	{
		cnt = ft_putchr_cnt('%');
	}
	else if (type == 'c')
	{
		cnt = ft_putchr_cnt(va_arg(*ap, int));
	}
	else if (type == 's')
	{
		cnt = ft_putstr_cnt(va_arg(*ap, char *));
	}
	else if (type == 'p')
	{
		cnt = ft_putstr_cnt("0x")
			+ putnbr_type((long)va_arg(*ap, void *), type);
	}
	else
	{
		cnt = putnbr_type(va_arg(*ap, int), type);
	}
	return (cnt);
}

int	putnbr_type(long nbr, char type)
{
	t_notation	notation;
	int			cnt;

	cnt = 0;
	init_struct(&notation, type);
	if (ft_strchr(SIGNED, type) && nbr < 0)
	{
		cnt = cnt + ft_putchr_cnt('-');
		nbr = -nbr;
	}
	if (ft_strchr(INT, type))
	{
		putnbr_int(nbr, notation, &cnt);
	}
	else if (ft_strchr(LONG, type))
	{
		putnbr_long(nbr, notation, &cnt);
	}
	return (cnt);
}

void	init_struct(t_notation *notation, char type)
{
	notation->base = 10;
	notation->capital = 0;
	if (ft_strchr(HEXA, type))
	{
		notation->base = 16;
	}
	if (ft_strchr(CAPITAL, type))
	{
		notation->capital = 16;
	}
}

void	putnbr_int(unsigned int nbr, t_notation notation, int *cnt)
{
	if (nbr < notation.base)
	{
		*cnt = *cnt + ft_putchr_cnt(DIGITS[nbr + notation.capital]);
	}
	else
	{
		putnbr_int(nbr / notation.base, notation, cnt);
		putnbr_int(nbr % notation.base, notation, cnt);
	}
}

void	putnbr_long(unsigned long nbr, t_notation notation, int *cnt)
{
	if (nbr < notation.base)
	{
		*cnt = *cnt + ft_putchr_cnt(DIGITS[nbr + notation.capital]);
	}
	else
	{
		putnbr_long(nbr / notation.base, notation, cnt);
		putnbr_long(nbr % notation.base, notation, cnt);
	}
}
