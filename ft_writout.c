/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:35:13 by wlo               #+#    #+#             */
/*   Updated: 2021/07/22 14:48:35 by wlo              ###   ########.fr       */
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
	if (s == 0)
		return ;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
}

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	if (!s)
		return (0);
	while (*s)
	{
		++length;
		s++;
	}
	return (length);
}

int	ft_printf_char(char c, int return_va)
{
	ft_putchar(c);
	return (++return_va);
}
