/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:35:40 by yehan             #+#    #+#             */
/*   Updated: 2022/03/24 10:27:17 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define ALLTYPES "%cspdiuxX"
# define HEXA "pxX"
# define SIGNED "di"
# define CAPITAL "X"
# define INT "cdiuxX"
# define LLONG "p"

typedef struct s_nbrfmt
{
	unsigned int	base;
	int				capital;
}	t_nbrfmt;

int		ft_printf(const char *format, ...);
int		putarg_cnt(char format, va_list *ap);
void	init_nbrfmt(char format, t_nbrfmt *nbrfmt);
int		putnbr_fmt(char format, long long nbr);
void	putnbr_fmt_ll(unsigned long long nbr, t_nbrfmt nbrfmt, int *cnt);
void	putnbr_fmt_i(unsigned int nbr, t_nbrfmt nbrfmt, int *cnt);

#endif