/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:33:37 by anassif           #+#    #+#             */
/*   Updated: 2019/11/16 23:43:40 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_handle_flags(t_flag *flag, int d)
{
    int j;
	int p;
	int m;
	
    j = strlen(ft_itoa(d));
	p = flag->prec;
	m = flag->width;
    if (flag->minus == 1)
    {
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(ft_itoa(d));
		while (m-- > flag->prec && m >= j)
			ft_putchar(' ');
	}
}
