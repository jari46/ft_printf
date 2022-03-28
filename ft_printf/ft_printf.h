/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:35:40 by yehan             #+#    #+#             */
/*   Updated: 2022/03/28 13:38:25 by yehan            ###   ########.fr       */
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
# define LONG "p"

typedef struct s_notation
{
	unsigned int	base;
	int				capital;
}	t_notation;

int		ft_printf(const char *format, ...);
int		putarg_cnt(va_list *ap, char type);
void	init_struct(t_notation *notation, char type);
int		putnbr_type(long nbr, char type);
void	putnbr_long(unsigned long nbr, t_notation notation, int *cnt);
void	putnbr_int(unsigned int nbr, t_notation notation, int *cnt);

#endif