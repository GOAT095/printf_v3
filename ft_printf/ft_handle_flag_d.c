/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:33:37 by anassif           #+#    #+#             */
/*   Updated: 2019/11/24 17:26:13 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_h_dn2(t_flag *flag, char *s, int j)
{
	if (flag->minus == 0 && flag->prec != -1)
	{
		while (flag->width > flag->prec + 1 && flag->width-- > j + 1)
			ft_putchar(' ');
		ft_putchar('-');
		if (j < flag->prec)
			while (flag->prec-- > j)
				ft_putchar('0');
		ft_putstr(s);
	}
	else if (flag->zero == 0 && flag->prec == -1)
	{
		while (flag->width-- > j + 1)
			ft_putchar(' ');
		ft_putchar('-');
		ft_putstr(s);
	}
	else if (flag->zero == 1 && (flag->prec == -1))
	{
		ft_putchar('-');
		while (flag->width-- > j + 1)
			ft_putchar('0');
		ft_putstr(s);
	}
}

void	ft_handle_negative(t_flag *flag, int d)
{
	int			j;
	int			p;
	int			m;
	long int	k;
	char		*s;

	k = (long int)d * -1;
	s = ft_itoa(k);
	j = ft_strlen(s);
	p = flag->prec;
	m = flag->width;
	if (flag->minus == 1)
	{
		ft_putchar('-');
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(s);
		while (m > flag->prec + 1 && m-- > j + 1)
			ft_putchar(' ');
	}
	else
		ft_h_dn2(flag, s, j);
	free(s);
}

void	ft_h_d1(t_flag *flag, char *s, int j)
{
	int p;

	p = flag->prec;
	if (j < flag->prec)
		while (p-- > j)
			ft_putchar('0');
	ft_putstr(s);
	while (flag->width > flag->prec && flag->width-- > j)
		ft_putchar(' ');
}

void	ft_h_d2(t_flag *flag, char *s, int j)
{
	int p;

	p = flag->prec;
	if (flag->minus == 0 && flag->prec != -1)
	{
		while (flag->width > flag->prec && flag->width-- > j)
			ft_putchar(' ');
		if (j < flag->prec)
			while (p-- > j)
				ft_putchar('0');
		ft_putstr(s);
	}
	else if (flag->zero == 0 && flag->prec == -1)
	{
		while (flag->width-- > j)
			ft_putchar(' ');
		ft_putstr(s);
	}
	else if (flag->zero == 1 && flag->prec == -1)
	{
		while (flag->width-- > j)
			ft_putchar('0');
		ft_putstr(s);
	}
}

void	ft_handle_flag_d(t_flag *flag, int d)
{
	int		j;
	int		p;
	char	*s;

	s = ft_itoa(d);
	j = ft_strlen(s);
	p = flag->prec;
	if (d < 0)
		ft_handle_negative(flag, d);
	else
	{
		if (flag->prec == 0 && d == 0)
			while (flag->width > flag->prec && flag->width-- > j - 1)
				ft_putchar(' ');
		else if (flag->minus == 1)
			ft_h_d1(flag, s, j);
		else
			ft_h_d2(flag, s, j);
	}
	free(s);
}
