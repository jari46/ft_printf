/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:35:40 by yehan             #+#    #+#             */
/*   Updated: 2022/03/23 18:20:38 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define ALLTYPES "%cspdiuxX"
# define HEXA "pxX"
# define SIGNED "di"
# define CAPITAL "X"

typedef struct s_nbrfmt
{
	unsigned int	base;
	int				capital;
}	t_nbrfmt;

int	ft_printf(const char *format, ...);

#endif