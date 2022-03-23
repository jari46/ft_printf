/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:23:27 by yehan             #+#    #+#             */
/*   Updated: 2022/03/23 18:16:43 by yehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_cnt(char *str)
{
	int	cnt;

	cnt = 0;
	if (str == NULL)
	{
		cnt = write(1, "(null)", 6);
		return (cnt);
	}
	while (*str)
	{
		cnt = cnt + write(1, str, 1);
		str++;
	}
	return (cnt);
}
