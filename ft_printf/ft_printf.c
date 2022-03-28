/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:19:59 by yehan             #+#    #+#             */
/*   Updated: 2022/03/28 11:39:46 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			cnt = cnt + putarg_cnt(&ap, *(format + 1));
			format++;
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}
