/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:32:27 by anassif           #+#    #+#             */
/*   Updated: 2019/11/16 23:42:28 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_atoii(const char *str)
{
	long long	n;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10;
		n = n + str[i] - '0';
		i++;
	}
	if (n < 0 && sign == 1)
		return (-1);
	if (n < 0 && sign == -1)
		return (0);
	return (n * sign);
}

static	int	count_numbers(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void		ft_init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->true_flag = 0;
	flag->width = 0;
	flag->prec = -1;
}

int			ft_printf(const char *s, ...)
{
	char	*str;
	va_list	l;
	int		i;
	t_flag	flag;

	i = 0;
	str = strdup(s);
	ft_init_flag(&flag);
	va_start(l, s);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%' && !(strchr("cspdiuxX", str[i])))
		{
			i++;
			ft_get_flags(str, &i, &flag, l);
		}
		if (strchr("cspdiuxX", str[i]))
		{
			if (str[i] == 'd')
			{
				ft_handle_flags(&flag, va_arg(l, int));
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(l);
	return (0);
}

int		main(void)
{
	char *d = "abc";
	int i = 123;
	//ft_printf("char===>%c \nint==>%d \nstring==>%s \n\n", 'a', -889, "LUL");
	//printf("char===>%c \nint==>%d \nstring==>%s", 'a', -889, "LUL");
	//ft_printf("%u\n", 42949);
	/*printf("original==> %X\n", d);
	ft_printf("mine======> %X\n\n", d);
	printf("original==> %x\n", d);
	ft_printf("mine======> %x\n", d);*/
	//printf("original==> %%p\n", x);
	printf("|%-015.*d|\n",12, i);
	ft_printf("|%-015.*d|\n",12, i);
	//printf("original==> |%-.d|",i);
	return (0);
}
