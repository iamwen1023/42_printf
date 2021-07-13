#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#include "ft_printf.h"

char    ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if ((*s) == (char)c)
            return ((char)s[1]);
        s++;
    }
    return (0);
}
void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putstr(char *s)
{
    int i;

    i = 0;
    if (!s)
        return ;
    while (s[i] != '\0')
        i++;
    write(1, s, i);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    char    type;
    int     word;
    void    *pointer;
    char    *arr_pointer;
        
    va_start(args, str);
    while(*str != '\0')
    {
        if (*str != '%')
            ft_putchar(*str);
        else 
        {
            type = ft_strchr(str, '%');
            if(type == 'c')
            {
                ft_putchar((unsigned char)va_arg(args, int));
            }
            else if (type  == 's')
                ft_putstr(va_arg(args, char *));
            else if (type == 'p')
            {
                pointer = &word;
                arr_pointer = ft_ultoa((unsigned long)(va_arg(args, void*)));
                ft_putstr("0x");
                ft_putstr(arr_pointer);
                ft_putstr("\n");
            } else if (type == 'i' || type == 'd')
            {
                arr_pointer = ft_itoa_base(va_arg(args, int), "0123456789", 10);
                ft_putstr(arr_pointer);
                ft_putstr("\n");
            }else if(type == 'u')
            {
                word = va_arg(args, int);
                if (word >= 0)
                    arr_pointer = ft_itoa_base(word, "0123456789", 10);
                
                printf("have not tested!\n");
            }
            else 
            {
                printf("have not tested!\n");
            }
        str++;
        }
    str++;
    // printf("in loop: %c\n", str[0]);
    }
    va_end(args);
    return (1);
}

int main () {
   long t;
   int *p;
   char *arr;

   t = -4294967294;
//    p = &s;
//    arr= ft_itoa((unsigned long long)p);

   // ft_printf("le mine: %p\n", &s);
    
    printf("original printf :%u\n", t);


   return 0;
}