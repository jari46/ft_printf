#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define TYPES "diuxXcsp%"

typedef struct
{
	bool	sign;
	int		base;
	int		capital;
} t_notation;

t_notation	init_note(char format)
{}

char	*ft_itoa_base(size_t n);

int putarg(char format, va_list *ap)
{
	char	str;//print number (use putstr)
	int		sum;

	sum = 0;
	if (format == 'c')
	{
		sum += putchar(va_arg(*ap, int));
	}
	else if (format == '%')
	{
		sum += putchar('%');
	}
	else if (format == 'p')
	{
		sum += putstr("0x");
		str = ft_itoa_base(va_arg(*ap, void *));
	}
	else if (format == 's')
	{
		str = ;
	}
	else
	{
		str = ft_itioa_base(va_arg(*ap, int));
	}
	sum += putstr(str);
	return (sum);
}

int	ft_printf(char *format, ...)
{
	va_list		ap;
	int			sum;

	va_start(ap, format);
	sum = 0;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			sum++;
		}
		else if (*(format + 1) && strchr(TYPES, *(format + 1)))
		{
			sum = sum + putarg(*(format + 1), &ap);
			format++;
		}
		format++;
	}
	va_end(ap);
	return (sum);
}
