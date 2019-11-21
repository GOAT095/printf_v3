/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:53:41 by anassif           #+#    #+#             */
/*   Updated: 2019/11/21 13:57:30 by anassif          ###   ########.fr       */
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
	if (flag->prec == -1 || flag->prec > j)
		flag->prec = j;
	m = flag->width;
	if (flag->minus == 1)
	{
		ft_s(s, flag->prec);
		while (m-- > flag->prec)
			ft_putchar(' ');
	}
	else if (flag->minus == 0 && flag->prec != -1)
	{
		while (m-- > flag->prec)
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

void	ft_h_c(t_flag *flag, char s)
{
	int m;
	
	m = flag->width;
	if (flag->width > 1 && flag->minus == 0)
	{
		while (m-- > 1)
			ft_putchar(' ');
		ft_putchar(s);
	}
	else if (flag->width > 1 && flag->minus == 1)
	{
		ft_putchar(s);
		while (m-- > 1)
			ft_putchar(' ');
	}
	else
		ft_putchar(s);
}