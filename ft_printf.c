/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:39 by wlo               #+#    #+#             */
/*   Updated: 2021/07/14 17:44:13 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((*s) == (char)c)
			return ((char)s[1]);
		s++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
}

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*s)
	{
		++length;
		s++;
	}
	return (length);
}

int	ft_printf_forchar(int return_value, va_list args, char specifier)
{
    char	*arr_pointer;

    if (specifier == 'c')
	{
		ft_putchar(va_arg(args, int));
		return_value++;
	}
	else /*if (specifier  == 's') */
	{
        arr_pointer = va_arg(args, char *);
        ft_putstr(arr_pointer);
        return_value = ft_strlen(arr_pointer) + return_value;
    }
    return (return_value);
}

int	ft_printf_foritoa(int return_value, va_list args, char specifier)
{
    char	*arr_pointer;

    if (specifier == 'i' || specifier == 'd')
    {
        arr_pointer = ft_itoa_base(va_arg(args, int), "0123456789", 10);
        ft_putstr(arr_pointer);
        return_value = ft_strlen(arr_pointer) + return_value;
        free(arr_pointer);
    }
    else if(specifier == 'u')
    {
        arr_pointer = ft_itoa_base(va_arg(args, unsigned int), "0123456789", 10);
        ft_putstr(arr_pointer);
        return_value = ft_strlen(arr_pointer) + return_value;
        free(arr_pointer);
    }
    else if (specifier == 'x')
    {
        arr_pointer = ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef", 16);
        ft_putstr(arr_pointer);
        return_value = ft_strlen(arr_pointer) + return_value;
        free(arr_pointer);
    }
    return (return_value);
}
int	ft_printf_forpointer(int return_value, va_list args, char specifier)
{
    char	*arr_pointer;

    arr_pointer = ft_ultoa((unsigned long)(va_arg(args, void*)));
    ft_putstr("0x");
    ft_putstr(arr_pointer);
    return_value = ft_strlen(arr_pointer) + return_value + 2;
    free(arr_pointer);
    return (return_value);
}

int ft_printf_char(char c, int return_value)
{
    ft_putchar(c);
    //return_value = return_value + 1;
    return (++return_value);
}

int ft_printf_real(const char *str, va_list args, int return_value)
{
    char    specifier;
    
    while(*str != '\0')
    {
        if (*str != '%')
            return_value = ft_printf_char(*str, return_value);
        else 
        {
            specifier = ft_strchr(str, '%');
            if(specifier == 'c' || specifier  == 's')
                return_value =  ft_printf_forchar(return_value, args, specifier);
            else if (specifier == 'p')   
                return_value =  ft_printf_forpointer(return_value, args, specifier);
            else if (specifier == 'i' || specifier == 'd' || specifier == 'u' || specifier == 'x')
                return_value =  ft_printf_foritoa(return_value, args, specifier);
            else
                return_value = ft_printf_char(*str, return_value);
            str++;
        }
    str++;
    }
    va_end(args);
    return (return_value);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int     return_value;
    
    return_value = 0;
    va_start(args, str);
    return_value = ft_printf_real(str, args, return_value);
    va_end(args);
    return (return_value);
}