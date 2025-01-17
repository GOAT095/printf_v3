/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:32:27 by anassif           #+#    #+#             */
/*   Updated: 2019/11/24 17:38:17 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_init_flag(t_flag *flag, int i)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
	return (i);
}

void		ft_handle_flags(int i, char *str, t_flag *flag, va_list l)
{
	char *a;

	if (str[i] == 'd' || str[i] == 'i')
		ft_handle_flag_d(flag, va_arg(l, int));
	else if (str[i] == 'u')
		ft_handle_flag_u(flag, va_arg(l, unsigned int));
	else if (str[i] == 'x')
		ft_h_x(flag, ft_small_hexa(va_arg(l, unsigned int)));
	else if (str[i] == 'X')
		ft_h_x(flag, ft_big_hexa(va_arg(l, unsigned int)));
	else if (str[i] == 'p')
		ft_h_p(flag, ft_p(va_arg(l, unsigned long long)));
	else if (str[i] == 's')
	{
		a = va_arg(l, char *);
		if (a == NULL)
			ft_h_s(flag, "(null)");
		else
			ft_h_s(flag, a);
	}
	else if (str[i] == 'c')
		ft_h_c(flag, va_arg(l, int));
	else if (str[i] == '%')
		ft_handle_pour(flag);
}

int			ft_printf(const char *s, ...)
{
	char	*str;
	va_list	l;
	int		i;
	t_flag	flag;

	str = ft_strdup(s);
	i = ft_init_flag(&flag, 0);
	va_start(l, s);
	g_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_get_flags(str, &i, &flag, &l);
			ft_handle_flags(i, str, &flag, l);
			i = ft_init_flag(&flag, i);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(l);
	free(str);
	return (g_count);
}
/*
int		main(void)
{
	// int x = 123456;
	// char *d = "abc";
	int i;
	int j;
	// ft_printf("char===>%c \nint==>%d \nstring==>%s \n\n", 'a', -889, "LUL");
	// printf("original==> %X\n", d);
	// ft_printf("char===>|%c|", 93);
	// printf("char===>|%*c|\n", -5,'a');
	// ft_printf("char===>|%*c|", -5,'a');
	// ft_printf("mine======> %x\n", d);
	// ft_printf("meeeeeee==> |%p|\n", (void *)0x0);
	// printf("original==> |%p|\n", (void *)0x0);
	// printf("original==> %p\n", &x);
	i = printf("Bla bla |%15.12d|\n", -123);
	printf("% d\n", i);
	j = ft_printf("Bla bla |%15.12d|\n", -123);
	 printf("% d\n", j);
	// printf("|%*.*u|\n", -4, 0, i);
	// printf("original==> |%-.d|",i);
	// ft_printf("|%s|", NULL);
	// ft_printf("|%05%|\n");
	// printf("|%05%|");
	return (0);
}
*/
