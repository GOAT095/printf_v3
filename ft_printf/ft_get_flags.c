/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:20:54 by anassif           #+#    #+#             */
/*   Updated: 2019/11/23 18:04:31 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_get_number(char *str, int *i)
{
	long long	n;
	int			sign;

	sign = 1;
	n = 0;
	while (str[*i] != '\0' && (str[*i] == ' ' ||
		(str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		n = n * 10;
		n = n + str[*i] - '0';
		(*i)++;
	}
	return (n * sign);
}

void	ft_get_flags(char *str, int *i, t_flag *flag, va_list *l)
{
	while (!(ft_strchr("%cspdiuxX", str[*i])) && str[*i] != '\0')
	{
		if (str[*i] == '-')
		{
			flag->minus = 1;
			(*i)++;
		}
		if (str[*i] == '0')
		{
			flag->zero = 1;
			(*i)++;
		}
		ft_get_flags_norm(str, i, flag, l);
	}
}

void	ft_get_flags_norm(char *str, int *i, t_flag *flag, va_list *l)
{
	if ((str[*i] >= '0' && str[*i] <= '9') || (str[(*i)] == '*'))
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			flag->width = ft_get_number(str, i);
		else if (str[(*i)++] == '*')
			flag->width = va_arg(*l, int);
		if (flag->width < 0)
		{
			flag->minus = 1;
			flag->width = -flag->width;
		}
	}
	ft_get_flags_norm2(str, i, flag, l);
}

void	ft_get_flags_norm2(char *str, int *i, t_flag *flag, va_list *l)
{
	int x;

	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] >= '0' && str[*i] <= '9')
			flag->prec = ft_get_number(str, i);
		else if (ft_strchr("cspdiuxX", str[*i]))
			flag->prec = 0;
		else if (str[(*i)] == '*')
		{
			(*i)++;
			x = va_arg(*l, int);
			(x >= 0 ? flag->prec = x : -1);
		}
	}
}
