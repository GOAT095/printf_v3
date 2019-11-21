/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:32:27 by anassif           #+#    #+#             */
/*   Updated: 2019/11/21 18:59:32 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*#define T(...)\
	printf("\n");\
	printf("Origina: => ");\
	printf(__VA_ARGS__);\
	printf("\n");\
	printf("Mine: => ");\
	ft_printf(__VA_ARGS__);\
	printf("\n");
*/
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
	char	*a;
	i = 0;
	str = strdup(s);
	ft_init_flag(&flag);
	va_start(l, s);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_get_flags(str, &i, &flag, &l);
			if (strchr("%cspdiuxX", str[i]))
			{
				if (str[i] == 'd' || str[i] == 'i')
					ft_handle_flag_d(&flag, va_arg(l, int));
				else if (str[i] == 'u')
					ft_handle_flag_u(&flag, va_arg(l, unsigned int));
				else if (str[i] == 'x')
				{
					a = ft_small_hexa(va_arg(l, unsigned int));
					ft_handle_flag_x(&flag, a);
					free(a);
				}
				else if (str[i] == 'X')
				{
					a = ft_big_hexa(va_arg(l, unsigned int));
					ft_handle_flag_X(&flag, a);
					free(a);
				}
				else if (str[i] == 'p')
				{
					a = ft_p(va_arg(l, unsigned long long));
					ft_handle_flag_p(&flag, a);
					free(a);
				}
				else if (str[i] == 's')
				{	
					a = va_arg(l, char *);
					if (a == NULL)
						ft_h_s(&flag, "(null)");
					else
						ft_h_s(&flag, a);
					free(a);
				}
				else if (str[i] == 'c')
					ft_h_c(&flag, va_arg(l, int));
				else if (str[i] == '%')
					ft_handle_pour(&flag);
			}
			ft_init_flag(&flag);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(l);
	free(str);
	return (count);
}

int		main(void)
{
	int x = 123456;
	//ft_printf("%d\n", INT32_MIN);
	//char *d = "abc";
	// unsigned int i = 56464;
	//ft_printf("char===>%c \nint==>%d \nstring==>%s \n\n", 'a', -889, "LUL");
	//printf("original==> %X\n", d);
	//printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%\n\n", 7,5, "ABC",15,0);
	//ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%\n", 7,5, "ABC",15,0);
	//ft_printf("char===>|%c|", 93);
	//printf("char===>|%*c|\n", -5,'a');
	//ft_printf("char===>|%*c|", -5,'a');
	// ft_printf("mine======> %x\n", d);
	ft_printf("original==> %x\n", x);
	//printf("original==> %p\n", &x);
	//printf("|%.3d|\n\n", 100);
	//ft_printf("|%.3d|", 100);
	// printf("|%*.*u|\n", -4, 0, i);
	//printf("original==> |%-.d|",i);
	//ft_printf("|%s|", NULL);
	//ft_printf("|%05%|\n");
	//printf("|%05%|");
	return (0);
}
