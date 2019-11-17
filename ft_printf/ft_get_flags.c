/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:20:54 by anassif           #+#    #+#             */
/*   Updated: 2019/11/17 17:57:43 by anassif          ###   ########.fr       */
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

void	ft_get_flags(char *str, int *i, t_flag *flag, va_list l)
{
	while (!(strchr("cspdiuxX", str[*i])))
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
		if ((str[*i] >= '0' && str[*i] <= '9') || (str[(*i)] == '*'))
		{
			if (str[*i] > '0' && str[*i] <= '9')
				flag->width = ft_get_number(str, i);
			else if (str[(*i)++] == '*')
				flag->width = va_arg(l, int);
		}
		if (str[*i] == '.')
		{
			(*i)++;
			if (str[*i] >= '0' && str[*i] <= '9')
				flag->prec = ft_get_number(str, i);
			else if (strchr("cspdiuxX", str[*i]))
				flag->prec = 0;
			else if (str[(*i)] == '*')
			{
				(*i)++;
				flag->prec = (va_arg(l, int) > 0 ? flag->prec = va_arg(l, int) : -1);
			}
		}
	}
	if (flag->minus != 0 || flag->zero != 0 || flag->width != 0 || flag->prec != -1)
		flag->true_flag = 1;
}

/*int main(void)
{
	t_flag	flag;
	flag.minus = 0;
	flag.true_flag = 0;
	flag.width = 0;
	flag.prec = -1;
	flag.zero = 0;
	int i = 1;
	ft_get_flags("%012.300d|\n", &i, &flag);
	return 0;
}*/