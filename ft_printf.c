/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:39 by wlo               #+#    #+#             */
/*   Updated: 2021/07/19 15:57:21 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_foritoa(int return_value, va_list args, char spec)
{
	char	*arr_pointer;
	char	*g_dec;

	g_dec = "0123456789";
	if (spec == 'i' || spec == 'd')
	{
		arr_pointer = ft_itoa_base(va_arg(args, int), g_dec, 10);
		ft_putstr(arr_pointer);
		return_value = ft_strlen(arr_pointer) + return_value;
		free(arr_pointer);
	}
	else if (spec == 'u')
	{
		arr_pointer = ft_itoa_base(va_arg(args, unsigned int), g_dec, 10);
		ft_putstr(arr_pointer);
		return_value = ft_strlen(arr_pointer) + return_value;
		free(arr_pointer);
	}
	return (return_value);
}

int	ft_printf_foritoa_x(int return_value, va_list args, char spec)
{
	char	*arr_pointer;
	char	*g_hex;
	char	*g_HEX;

	g_hex = "0123456789abcdef";
	g_HEX = "0123456789ABCDEF";
	if (spec == 'x')
	{
		arr_pointer = ft_itoa_base(va_arg(args, unsigned int), g_hex, 16);
		ft_putstr(arr_pointer);
		return_value = ft_strlen(arr_pointer) + return_value;
		free(arr_pointer);
	}
	else
	{	
		arr_pointer = ft_itoa_base(va_arg(args, unsigned int), g_HEX, 16);
		ft_putstr(arr_pointer);
		return_value = ft_strlen(arr_pointer) + return_value;
		free(arr_pointer);
	}
	return (return_value);
}

int	ft_printf_forpointer(int return_value, va_list args)
{
	char	*arr_pointer;

	arr_pointer = ft_ultoa((unsigned long)(va_arg(args, void *)));
	ft_putstr("0x");
	ft_putstr(arr_pointer);
	return_value = ft_strlen(arr_pointer) + return_value + 2;
	free(arr_pointer);
	return (return_value);
}

int	ft_printf_real(const char *str, va_list args, int return_value)
{
	char	spec;

	while (*str != '\0')
	{
		if (*str != '%')
			return_value = ft_printf_char(*str, return_value);
		else
		{
			spec = ft_strchr(str, '%');
			if (spec == 'c' || spec == 's')
				return_value = ft_printf_forchar(return_value, args, spec);
			else if (spec == 'p')
				return_value = ft_printf_forpointer(return_value, args);
			else if (spec == 'i' || spec == 'd' || spec == 'u')
				return_value = ft_printf_foritoa(return_value, args, spec);
			else if (spec == 'x' || spec == 'X')
				return_value = ft_printf_foritoa_x(return_value, args, spec);
			else
				return_value = ft_printf_char(*str, return_value);
			str++;
		}
		str++;
	}
	return (return_value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		return_value;

	return_value = 0;
	va_start(args, str);
	return_value = ft_printf_real(str, args, return_value);
	va_end(args);
	return (return_value);
}
