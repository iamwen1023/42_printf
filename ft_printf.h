#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
long    digit_count(unsigned long n);
void    ft_ultoa_2(unsigned long long_n, long len, char **arr);
char    *ft_ultoa(unsigned long n);

long	length(char *src);
int		digit_lenght(long nb, long len);
char	*ft_itoa_base2(long nb, long len, char *arr, char *base);
char	*ft_itoa_base(long nb, char *base, long len);
char	*rev_string(char *arr);


#endif