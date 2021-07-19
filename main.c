#include "ft_printf.h"

int main () {
   int t;
   //int *p;
   char *arr;
   int re_value;

   t = -5;
   arr = "hello!!";

   /*re_value = ft_printf("le mine: %d%s%p\n",t, arr ,&t);
   printf("return :%d\n", re_value);
   re_value = printf("le mine: %s%d%p\n", arr,t ,&t);
   printf("return :%d\n", re_value);*/

   // re_value = ft_printf("le mine:\n d: %d\n i: %i\n c: %c\n s: %s\n p: %p\n u: %u\n x: %x\n X: %X\n", 0, 2147483647, -500, "", -1, -50, -2147483647, -2147483647);
   // printf("return :%d\n\n", re_value);
   // re_value = printf("le mine:\n d: %ld\n i: %i\n c: %c\n s: %s\n p: %p\n u: %lu\n x: %x\n X: %X\n", 0, 2147483647, -500, "", -1, -50, -2147483647, -2147483647);
   // printf("return :%d\n", re_value);
    //printf("original printf :%.5d\n", t);

    // char *str = "%p %p %p\n";
    // int moi = ft_printf(str, "", "Hello", NULL);
    // printf("Result : %d\n\n", moi);

    // int vrai = printf(str, "", "Hello", NULL);
    // printf("Result : %d\n", vrai);

   return 0;
}