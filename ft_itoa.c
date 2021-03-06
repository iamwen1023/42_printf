/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:24 by wlo               #+#    #+#             */
/*   Updated: 2021/07/15 15:20:06 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	length(char *src)
{
	long	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

long	digit_lenght(long nb, long len)
{
	long	size;

	size = 1;
	if (nb < 0)
		nb = nb * (-1);
	while (nb >= len)
	{
		nb = nb / len;
		size++;
	}
	return (size);
}

char	*ft_itoa_base2(long nb, long len, char *arr, char *base)
{
	int	i;

	i = 0;
	while (nb >= len)
	{
		arr[i] = base[nb % len];
		nb = nb / len;
		i++;
	}
	arr[i] = base[nb % len];
	return (arr);
}

char	*rev_string(char *arr)
{
	int		i;
	long	len;
	char	c;

	i = 0;
	len = length(arr);
	while (i < len / 2)
	{
		c = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = c;
		i++;
	}
	return (arr);
}

char	*ft_itoa_base(long nb, char *base, long len)
{
	long		length_nb;
	char		*arr;
	int			sign;

	length_nb = digit_lenght(nb, len);
	sign = 0;
	if (nb < 0)
	{
		length_nb++;
		sign = 1;
		nb = nb * (-1);
	}
	arr = (char *)malloc(sizeof(char) * (length_nb + 1));
	if (!arr)
		return (0);
	arr = ft_itoa_base2(nb, len, arr, base);
	if (sign == 1)
		arr[length_nb - 1] = '-';
	arr[length_nb] = '\0';
	arr = rev_string(arr);
	return (arr);
}
