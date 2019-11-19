/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:32:27 by anassif           #+#    #+#             */
/*   Updated: 2019/11/19 20:27:39 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
int count;
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
			if (strchr("cspdiuxX", str[i]))
			{
				if (str[i] == 'd' || str[i] == 'i')
					ft_handle_flag_d(&flag, va_arg(l, int));
				else if (str[i] == 'u')
					ft_handle_flag_u(&flag, va_arg(l, unsigned int));
				else if (str[i] == 'x')
					ft_handle_flag_x(&flag, ft_small_hexa(va_arg(l, unsigned int)));
				else if (str[i] == 'X')
					ft_handle_flag_X(&flag, ft_big_hexa(va_arg(l, unsigned int)));
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(l);
	return (count);
}
/*
int		main(void)
{
	//ft_printf("%d\n", INT32_MIN);
	//char *d = "abc";
	// unsigned int i = 56464;
	//ft_printf("char===>%c \nint==>%d \nstring==>%s \n\n", 'a', -889, "LUL");
	//printf("char===>%c \nint==>%d \nstring==>%s", 'a', -889, "LUL");
	//ft_printf("%u\n", 42949);
	//printf("original==> %X\n", d);
	ft_printf("mine======> |%x|\n", 0);
	printf("original==> |%x|\n", 0);
	// ft_printf("mine======> %x\n", d);
	//printf("original==> %%p\n", x);
	//printf("|%015d|\n", i);
	// ft_printf("|%*.*u|\n", -4, 0, i);
	// printf("|%*.*u|\n", -4, 0, i);
	//printf("original==> |%-.d|",i);
	return (0);
}*/