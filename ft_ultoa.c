/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:52:03 by wlo               #+#    #+#             */
/*   Updated: 2021/07/14 15:52:06 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    hex[16]="0123456789abcdef";

long    digit_count(unsigned long n)
{
    int    len;

    len = 1;
    while (n >= 16)
    {
        n = n / 16;
        len++;
    }
    return (len);
}

void    ft_ultoa_2(unsigned long long_n, long len, char **arr)
{
    long    i;
    
    i = len - 1;
    while (long_n >= 16)
    {
        (*arr)[i] = hex[long_n % 16];
        long_n = long_n / 16;
        i--;
    }
    (*arr)[i] = hex[long_n % 16];
    (*arr)[len] = '\0';
}


char    *ft_ultoa(unsigned long n)
{
    long        len;
    char        *arr;

    len = digit_count(n);
    arr = malloc((len + 1) * sizeof(char));
    if (!arr)
        return (0);
    ft_ultoa_2(n, len, &arr);
    return (arr);
}
