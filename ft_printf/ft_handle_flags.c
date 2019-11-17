/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:33:37 by anassif           #+#    #+#             */
/*   Updated: 2019/11/18 00:19:59 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_negative(t_flag *flag, int d)
{
	int j;
	int p;
	int m;
	
	j = strlen(ft_itoa(d)) - 1;
	d = -d;
	p = flag->prec;
	m = flag->width;
	if (flag->minus == 1)
	{
		ft_putchar('-');
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(ft_itoa(d));
		while (m > flag->prec + 1  && m-- > j + 1)
			ft_putchar(' ');
	}
	else if (flag->minus == 0 && flag->prec != -1 /*&& flag->zero == 0*/)
	{
		while (m > flag->prec + 1 && m-- > j + 1)
			ft_putchar(' ');
		ft_putchar('-');
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(ft_itoa(d));
	}
	else if (flag->zero == 0 && flag->prec == -1)
	{
		while (m-- > j + 1)
			ft_putchar(' ');
		ft_putchar('-');
		ft_putstr(ft_itoa(d));
	}
	else if (flag->zero == 1 && (flag->prec == -1))
	{
		ft_putchar('-');
		while (m-- > j + 1)
			ft_putchar('0');
		ft_putstr(ft_itoa(d));
	}
}

void    ft_handle_flags(t_flag *flag, int d)
{
	int j;
	int p;
	int m;
	
	j = strlen(ft_itoa(d));
	p = flag->prec;
	m = flag->width;
	if (d < 0)
		ft_handle_negative(flag, d);
	else
	{
		//last update is here 
		if (flag->prec == 0 && d == 0)
			while (m > flag->prec && m-- > j - 1)
				ft_putchar(' ');
		//this
		else if (flag->minus == 1)
		{
			if (j < flag->prec)
				while (p-- > j)
					ft_putchar('0');
			ft_putstr(ft_itoa(d));
			while (m > flag->prec && m-- > j)
				ft_putchar(' ');
		}
		else if (flag->minus == 0 && flag->prec != -1)
		{
			while (m > flag->prec && m-- > j)
				ft_putchar(' ');
			if (j < flag->prec)
				while (p-- > j)
					ft_putchar('0');
			ft_putstr(ft_itoa(d));
		}
		else if (flag->zero == 0 && flag->prec == -1)
		{
			while (m-- > j)
				ft_putchar(' ');
			ft_putstr(ft_itoa(d));
		}
		else if (flag->zero == 1 && flag->prec == -1)
		{
			while (m-- > j)
				ft_putchar('0');
			ft_putstr(ft_itoa(d));
		}
	}
}
