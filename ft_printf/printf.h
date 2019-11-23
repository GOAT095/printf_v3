/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:21:00 by anassif           #+#    #+#             */
/*   Updated: 2019/11/23 21:50:38 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int count;
typedef struct  flag
{
    int zero;
    int minus;
    int width;
    int prec;
}               t_flag;

char	*ft_itoa(long int n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *s);
void	ft_putchar(int c);
void	ft_putnbr(int nb);
int		ft_printf(const char *s, ...);
char	*ft_small_hexa(unsigned int x);
char	*ft_big_hexa(unsigned int x);
char	*ft_p(unsigned long long x);
char	*ft_strrev(char *str);
void	ft_get_flags(char *str, int *i, t_flag *flag, va_list *l);
void	ft_get_flags_norm(char *str, int *i, t_flag *flag, va_list *l);
void	ft_get_flags_norm2(char *str, int *i, t_flag *flag, va_list *l);
int		ft_get_number(char *str, int *i);
void    ft_handle_flag_d(t_flag *flag, int d);
void    ft_handle_flag_u(t_flag *flag, unsigned int d);
void	ft_handle_u_more(t_flag *flag, char *s, int m, int j);
void    ft_h_x(t_flag *flag, char *s);
void	ft_h_x_more(t_flag *flag, char *s, int m, int j);
void    ft_h_p(t_flag *flag, char *s);
void    ft_handle_pour(t_flag *flag);
void    ft_h_s(t_flag *flag, char *s);
void	ft_h_c(t_flag *flag, char s);
#endif