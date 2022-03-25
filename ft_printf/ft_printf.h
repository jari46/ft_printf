/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:35:40 by yehan             #+#    #+#             */
/*   Updated: 2022/03/24 17:26:28 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define DIGITS "0123456789abcdef0123456789ABCDEF"
# define ALLTYPES "%cspdiuxX"
# define HEXA "pxX"
# define CAPITAL "X"
# define SIGNED "di"
# define INT "cdiuxX"
# define LLONG "p"

typedef struct s_notation
{
	unsigned int	base;
	int				capital;
}	t_notation;

int		ft_printf(const char *format, ...);
int		putarg_cnt(va_list *ap, char type);
void	init_struct(t_notation *notation, char type);
int		putnbr_type(long long nbr, char type);
void	putnbr_llong(unsigned long long nbr, t_notation notation, int *cnt);
void	putnbr_int(unsigned int nbr, t_notation notation, int *cnt);

#endif