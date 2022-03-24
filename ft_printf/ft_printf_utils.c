/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:52:33 by yehan             #+#    #+#             */
/*   Updated: 2022/03/24 17:29:53 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putarg_cnt(char format, va_list *ap)
{
	int			cnt;

	cnt = 0;
	if (format == '%')
	{
		cnt = ft_putchr_cnt('%');
	}
	else if (format == 'c')
	{
		cnt = ft_putchr_cnt(va_arg(*ap, int));
	}
	else if (format == 's')
	{
		cnt = ft_putstr_cnt(va_arg(*ap, char *));
	}
	else if (format == 'p')
	{
		cnt = ft_putstr_cnt("0x")
			+ putnbr_fmt(format, (long long)va_arg(*ap, void *));
	}
	else
	{
		cnt = putnbr_fmt(format, va_arg(*ap, int));
	}
	return (cnt);
}

void	init_nbrfmt(char format, t_nbrfmt *nbrfmt)
{
	nbrfmt->base = 10;
	nbrfmt->capital = 0;
	if (ft_strchr(HEXA, format))
	{
		nbrfmt->base = 16;
	}
	if (ft_strchr(CAPITAL, format))
	{
		nbrfmt->capital = 16;
	}
}

int	putnbr_fmt(char format, long long nbr)
{
	int			cnt;
	t_nbrfmt	nbrfmt;

	cnt = 0;
	init_nbrfmt(format, &nbrfmt);
	if (ft_strchr(SIGNED, format) && nbr < 0)
	{
		cnt = cnt + ft_putchr_cnt('-');
		nbr = -nbr;
	}
	if (ft_strchr(INT, format))
	{
		putnbr_fmt_i(nbr, nbrfmt, &cnt);
	}
	else if (ft_strchr(LLONG, format))
	{
		putnbr_fmt_ll(nbr, nbrfmt, &cnt);
	}
	return (cnt);
}

void	putnbr_fmt_ll(unsigned long long nbr, t_nbrfmt nbrfmt, int *cnt)
{
	if (nbr < nbrfmt.base)
	{
		*cnt = *cnt + ft_putchr_cnt(DIGITS[nbr + nbrfmt.capital]);
	}
	else
	{
		putnbr_fmt_ll(nbr / nbrfmt.base, nbrfmt, cnt);
		putnbr_fmt_ll(nbr % nbrfmt.base, nbrfmt, cnt);
	}
}

void	putnbr_fmt_i(unsigned int nbr, t_nbrfmt nbrfmt, int *cnt)
{
	if (nbr < nbrfmt.base)
	{
		*cnt = *cnt + ft_putchr_cnt(DIGITS[nbr + nbrfmt.capital]);
	}
	else
	{
		putnbr_fmt_i(nbr / nbrfmt.base, nbrfmt, cnt);
		putnbr_fmt_i(nbr % nbrfmt.base, nbrfmt, cnt);
	}
}
