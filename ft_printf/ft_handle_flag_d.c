/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:33:37 by anassif           #+#    #+#             */
/*   Updated: 2019/11/21 13:40:39 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_negative(t_flag *flag, int d)
{
	int j;
	int p;
	int m;
	long int k;
	
	j = strlen(ft_itoa(d)) - 1;
	k = (long int)d * -1;
	p = flag->prec;
	m = flag->width;
	if (flag->minus == 1)
	{
		ft_putchar('-');
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(ft_itoa(k));
		while (m > flag->prec + 1  && m-- > j + 1)
			ft_putchar(' ');
	}
	else if (flag->minus == 0 && flag->prec != -1)
	{
		while (m > flag->prec + 1 && m-- > j + 1)
			ft_putchar(' ');
		ft_putchar('-');
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(ft_itoa(k));
	}
	else if (flag->zero == 0 && flag->prec == -1)
	{
		while (m-- > j + 1)
			ft_putchar(' ');
		ft_putchar('-');
		ft_putstr(ft_itoa(k));
	}
	else if (flag->zero == 1 && (flag->prec == -1))
	{
		ft_putchar('-');
		while (m-- > j + 1)
			ft_putchar('0');
		ft_putstr(ft_itoa(k));
	}
}

void    ft_handle_flag_d(t_flag *flag, int d)
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
		if (flag->prec == 0 && d == 0)
			while (m > flag->prec && m-- > j - 1)
				ft_putchar(' ');
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
/*
void    ft_handle_pour(t_flag *flag)
{
	int m;
	int p;
	m = flag->width;
	p = flag->prec;
	if (flag->width == 1 || flag->prec != -1 && flag->zero == 0)
	{
		while (m-- > 0)
			ft_putchar(' ');
		while (p-- > 0)
			ft_putchar(' ');
	}
	else if (flag->zero == 1)
		while (m-- > 0)
			ft_putchar('0');
}*/
