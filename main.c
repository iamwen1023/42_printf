#include "ft_printf.h"

int main () {
   int t;
   //int *p;
   char *arr;
   int re_value;

   t = 1;
   arr = NULL;

   /*re_value = ft_printf("le mine: %d%s%p\n",t, arr ,&t);
   printf("return :%d\n", re_value);
   re_value = printf("le mine: %s%d%p\n", arr,t ,&t);
   printf("return :%d\n", re_value);*/

   re_value = ft_printf("le mine:\n d: %d\n i: %i\n c: %c\n s: %s\n p: %p\n u: %u\n x: %x\n X: %X\n", 0, 2147483647, -500, "", &t, 50, -2147483647, -2147483647);
   printf("return :%d\n\n", re_value);
   re_value = printf("le mine:\n d: %d\n i: %i\n c: %c\n s: %s\n p: %p\n u: %u\n x: %x\n X: %X\n", 0, 2147483647, -500, "", &t, 50, -2147483647, -2147483647);
   printf("return :%d\n", re_value);
   // re_value= ft_printf("hello, %s\n", NULL);
   // printf("return :%d\n\n", re_value);
   // re_value = printf("hello, %s\n", NULL);
   // printf("return :%d\n\n", re_value);
    // char *str = "%p %p %p\n";
    // int moi = ft_printf(str, "", "Hello", NULL);
    // printf("Result : %d\n\n", moi);

    // int vrai = printf(str, "", "Hello", NULL);
    // printf("Result : %d\n", vrai);

   return 0;
}