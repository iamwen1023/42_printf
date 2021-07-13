# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


char	decimal[10] = "0123456789";
char	octal[8] = "01234567";
char	hexadecimal[16]="0123456789abcdef";
char	binary[2] = "01";


long	length(char *src)
{
	long i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int		digit_lenght(long nb, long len)
{
	long size;

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
	int i;

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
	int		len;
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

char	*ft_btoa_base(unsigned long nb, char *base, long len)
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
	if (!(arr = (char*)malloc(sizeof(char) * (length_nb + 1))))
		return (0);
	arr = ft_itoa_base2(nb, len, arr, base);
	if (sign == 1)
		arr[length_nb - 1] = '-';
	arr[length_nb] = '\0';
	arr = rev_string(arr);
	return (arr);
}



