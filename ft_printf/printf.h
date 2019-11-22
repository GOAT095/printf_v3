/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:21:00 by anassif           #+#    #+#             */
/*   Updated: 2019/11/22 14:26:09 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include "libft/libft.h"

int count;
typedef struct  flag
{
    int zero;
    int minus;
    int width;
    int prec;
    int true_flag;
}               t_flag;

char	*ft_itoa(long int n);
void	ft_putstr(char *s);
void	ft_putchar(int c);
void	ft_putnbr(int nb);
int		ft_printf(const char *s, ...);
void	ft_put_unsigned(unsigned int nb);
char	*ft_small_hexa(unsigned int x);
char	*ft_big_hexa(unsigned int x);
char	*ft_p(unsigned long long x);
void	ft_min_width(char *s, int j);
char	*ft_itoau(unsigned int n);
char	*ft_strrev(char *str);
// char	*ft_small_hexaa(unsigned int x);
// char	*ft_big_hexaa(unsigned int x);
char    *ft_p100tage_p(unsigned long long x);
void	ft_flag_zero(char *s, int j);
char	*ft_precission(char *str, int j);
void	ft_get_flags(char *str, int *i, t_flag *flag, va_list *l);
int		ft_get_number(char *str, int *i);
void    ft_handle_flag_d(t_flag *flag, int d);
void    ft_handle_flag_u(t_flag *flag, unsigned int d);
void    ft_handle_flag_x(t_flag *flag, char *s);
void    ft_handle_flag_p(t_flag *flag, char *s);
void    ft_handle_pour(t_flag *flag);
void    ft_h_s(t_flag *flag, char *s);
void	ft_h_c(t_flag *flag, char s);
#endif