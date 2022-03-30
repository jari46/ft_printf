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

/* 허브의 역할. 인자와 타입을 받아, 타입 별로 맞는 함수로 넘겨준다. 
** 크게 putchr, putstr, putnbr 3개 함수를 사용한다. */
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

/* 가장 큰 자료형에 우선 담는다 */
int	putnbr_type(long nbr, char type)
{
	t_notation	notation;
	int			cnt;

	cnt = 0;
	init_struct(&notation, type);

	/* 해당 type의 디폴트 자료형이 signed일 때 양수로 만든다. 
	** 단 signed가 아닌데 음수로 들어온 경우는 그대로 진행한다 */
	if (ft_strchr(SIGNED, type) && nbr < 0)
	{
		cnt = cnt + ft_putchr_cnt('-');
		nbr = -nbr;
	}

	/* printf의 오버플로 언더플로를 흉내내기 위해,
	** 디폴트 length(어떤 자료형으로 인식할지에 대한 필드)에 맞는 putnbr_*에 각각 넘겨준다. */
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

/* arg를 어떻게 '인식'할지에 대한 것은 바로 처리하고,
** 어떻게 '표기notation'할 것인지에 대한 것은 구조체에 담는다. */
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

/* 나눗셈을 한 번 거친 후 출력되기 때문에 INT_MIN도 언더플로우 없이 제대로 출력될 수 있다. */
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
