/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:30:09 by anassif           #+#    #+#             */
/*   Updated: 2019/11/22 14:32:59 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_handle_flag_x(t_flag *flag, char *s)
{
	int j;
	int p;
	int m;
	
	j = strlen(s);
	p = flag->prec;
	m = flag->width;
	if (flag->prec == 0 && s[0] == '0')
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
	else if (flag->minus == 0 && flag->prec != -1)
	{
		while (m > flag->prec && m-- > j)
			ft_putchar(' ');
		if (j < flag->prec)
			while (p-- > j)
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
}

void    ft_handle_flag_p(t_flag *flag, char *s)
{
	int j;
	int p;
	int m;
	
	j = strlen(s);
	p = flag->prec;
	m = flag->width;
	if (flag->prec == 0 && s[2] == '0')
	{
		if (flag->minus == 0)
		{
			while (m > flag->prec && m-- > j - 1)
				ft_putchar(' ');
			ft_putstr("0x");
		}
		else
		{
			ft_putstr("0x");
			while (m > flag->prec && m-- > j - 1)
				ft_putchar(' ');
		}
		
	}
	else if (flag->minus == 1)
	{
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(s);
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
}