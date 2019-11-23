/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:30:09 by anassif           #+#    #+#             */
/*   Updated: 2019/11/23 21:46:52 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_h_x(t_flag *flag, char *s)
{
	int		j;
	int		p;
	int		m;

	j = ft_strlen(s);
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
	else
		ft_h_x_more(flag, s, m, j);
}

void	ft_h_x_more(t_flag *flag, char *s, int m, int j)
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
	if (ft_strncmp(s, "0", 100))
		free(s);
}

void	ft_h_p(t_flag *flag, char *s)
{
	int j;
	int p;
	int m;

	j = ft_strlen(s);
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
	if (ft_strncmp(s, "0x0", 100))
		free(s);
}
