/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:45:48 by anassif           #+#    #+#             */
/*   Updated: 2019/11/24 15:20:34 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_pour(t_flag *flag)
{
	int m;
	int p;

	m = flag->width;
	p = flag->prec;
	if (flag->width != 0 && flag->zero == 1)
	{
		if (flag->minus == 0)
		{
			while (m-- > 1)
				ft_putchar('0');
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			while (m-- > 1)
				ft_putchar(' ');
		}
	}
	else
		ft_handle_pour2(flag);
}

void	ft_handle_pour2(t_flag *flag)
{
	int m;

	m = flag->width;
	if (flag->width != 0 && flag->zero == 0)
	{
		if (flag->minus == 0)
		{
			while (m-- > 1)
				ft_putchar(' ');
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			while (m-- > 1)
				ft_putchar(' ');
		}
	}
	else
		ft_putchar('%');
}
