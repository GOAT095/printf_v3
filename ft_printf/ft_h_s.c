/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:53:41 by anassif           #+#    #+#             */
/*   Updated: 2019/11/20 21:14:05 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void ft_s(char *s, int j)
{
	int i;

	i = 0;
	while (s[i] != '\0' && i < j)
	{
		ft_putchar(s[i]);
		i++;
	}
}

void    ft_h_s(t_flag *flag, char *s)
{
    int j;
	int p;
	int m;
	
	j = strlen(s);
	p = flag->prec;
	m = flag->width;
	if (flag->minus == 1)
	{
		ft_s(s, flag->prec);
		while (p-- > j)
			ft_putchar(' ');
		while (m-- > flag->prec)
			ft_putchar(' ');
	}
	else if (flag->minus == 0 && flag->prec != -1)
	{
		while (m-- > flag->prec)
			ft_putchar(' ');
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar(' ');
		ft_s(s, flag->prec);
	}
	else if (flag->prec == -1)
	{
		while (m-- > j)
			ft_putchar(' ');
		ft_putstr(s);
	}
}