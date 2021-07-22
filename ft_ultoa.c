/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:52:03 by wlo               #+#    #+#             */
/*   Updated: 2021/07/22 14:48:10 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// g_hex[16] = "0123456789abcdef";

long	digit_count(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_ultoa_2(unsigned long long_n, long len, char **arr)
{
	long	i;
	char	*g_hex;

	g_hex = "0123456789abcdef";
	i = len - 1;
	while (long_n >= 16)
	{
		(*arr)[i] = g_hex[long_n % 16];
		long_n = long_n / 16;
		i--;
	}
	(*arr)[i] = g_hex[long_n % 16];
	(*arr)[len] = '\0';
}

char	*ft_ultoa(unsigned long n)
{
	long	len;
	char	*arr;

	len = digit_count(n);
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	ft_ultoa_2(n, len, &arr);
	return (arr);
}

int	ft_printf_forchar(int return_va, va_list args, char spec)
{
	char	*arr_pointer;

	if (spec == 'c')
	{
		ft_putchar(va_arg(args, int));
		return_va++;
	}
	else
	{
		arr_pointer = va_arg(args, char *);
		if (!arr_pointer)
			arr_pointer = "(null)";
		ft_putstr(arr_pointer);
		return_va = ft_strlen(arr_pointer) + return_va;
	}
	return (return_va);
}
