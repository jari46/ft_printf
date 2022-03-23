/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:19:59 by yehan             #+#    #+#             */
/*   Updated: 2022/03/23 18:20:48 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_nbrfmt(char format, t_nbrfmt *nbrfmt)
{
	if (ft_strchr(HEXA, format))
		nbrfmt->base = 16;
	else
		nbrfmt->base = 10;
	if (ft_strchr(CAPITAL, format))
		nbrfmt->capital = 16;
	else
		nbrfmt->capital = 0;
}

static void	putnbr_fmt2(t_nbrfmt nbrfmt, unsigned long long nbr, int *cnt)
{
	char	*digit;

	digit = "0123456789abcdef0123456789ABCDEF";
	if (nbr < nbrfmt.base)
	{
		*cnt += ft_putchr_cnt(digit[nbr + nbrfmt.capital]);
	}
	else
	{
		putnbr_fmt2(nbrfmt, nbr / nbrfmt.base, cnt);
		putnbr_fmt2(nbrfmt, nbr % nbrfmt.base, cnt);
	}
}

static int	putnbr_fmt(char format, long long nbr)
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
	putnbr_fmt2(nbrfmt, nbr, &cnt);
	return (cnt);
}

static int	putarg_cnt(char format, va_list *ap)
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

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt;

	va_start(ap, format);
	cnt = 0;
	while (*format)
	{
		if (*format != '%')
		{
			cnt = cnt + ft_putchr_cnt(*format);
		}
		else if (*(format + 1) && ft_strchr(ALLTYPES, *(format + 1)))
		{
			cnt = cnt + putarg_cnt(*(format + 1), &ap);
			format++;
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}
