#include "ft_printf.h"

typedef struct printf {
	char	*flag;
	char	*width;
	char	*precision;
	char	*lenght;
	char	*specifier;
} ex_printf;

int	if_is_a_flag(char s)
{
	if (s == '-' || s == '+')
		return 1;
	else 
		return 0;
}

char *manage_di_flages(char *rest, va_list args, int *return_value_a)
{
	
	while (if_is_a_flag(*rest) == 1 )
	{
	
		
		rest++;
	}
	return 0;
}


int	ft_printf_bonus(const char *str, va_list args, int return_value)
{
	char	*rest;

	rest = (char *)str;
	while (*rest != '\0')
	{
		if (*rest == '%')
		{
			rest = manage_di_flages(rest,  args, &return_value);
		}
		else
			return_value = ft_printf_char(*rest, return_value);
		rest++;
	}
	return (return_value);
}

int	ft_printf_bo(const char *str, ...)
{
	va_list	args;
	int		return_value;

	return_value = 0;
	va_start(args, str);
	return_value = ft_printf_bonus(str, args, return_value);
	va_end(args);
	return (return_value);
}




int main(){

	int re_value;

	re_value = printf("hello : %+\nxfggf", 42);
	printf("re_value : %d", re_value);
	return 0;
}