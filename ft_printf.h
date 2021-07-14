/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:46 by wlo               #+#    #+#             */
/*   Updated: 2021/07/14 17:44:13 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

char    ft_strchr(const char *s, int c);
void    ft_putchar(char c);
void    ft_putstr(char *s);
int		ft_strlen(const char *s);
int		ft_printf_forchar(int return_value, va_list args, char specifier);
int		ft_printf_foritoa(int return_value, va_list args, char specifier);
int		ft_printf_forpointer(int return_value, va_list args, char specifier);
int		ft_printf_char(char c, int return_value);
int		ft_printf_real(const char *str, va_list args, int return_value);
int		ft_printf(const char *str, ...);


long    digit_count(unsigned long n);
void    ft_ultoa_2(unsigned long long_n, long len, char **arr);
char    *ft_ultoa(unsigned long n);

long	length(char *src);
long	digit_lenght(long nb, long len);
char	*ft_itoa_base2(long nb, long len, char *arr, char *base);
char	*ft_itoa_base(long nb, char *base, long len);
char	*rev_string(char *arr);


#endif
