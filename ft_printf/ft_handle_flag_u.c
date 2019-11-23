/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:59 by anassif           #+#    #+#             */
/*   Updated: 2019/11/23 21:50:05 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_u_more(t_flag *flag, char *s, int m, int j)
{
	if (flag->minus == 0 && flag->prec != -1)
	{
		while (m > flag->prec && m-- > j)
			ft_putchar(' ');
		if (j < flag->prec)
			while (flag->prec-- > j)
				ft_putchar('0');
		ft_putstr(s);
	}
	else if (flag->zero == 0 && flag->prec == -1)
	{
		while (m-- > j)
			ft_putchar(' ');
		ft_putstr(s);
	}
	else if (flag->zero == 1 && flag->prec == -1)
	{
		while (m-- > j)
			ft_putchar('0');
		ft_putstr(s);
	}
	free(s);
}

void	ft_handle_flag_u(t_flag *flag, unsigned int d)
{
	int		j;
	int		p;
	int		m;
	char	*s;

	s = ft_itoa(d);
	j = ft_strlen(s);
	p = flag->prec;
	m = flag->width;
	if (flag->prec == 0 && d == 0)
		while (m > flag->prec && m-- > j - 1)
			ft_putchar(' ');
	else if (flag->minus == 1)
	{
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(s);
		while (m > flag->prec && m-- > j)
			ft_putchar(' ');
	}
	else
		ft_handle_u_more(flag, s, m, j);
}
