#include "ft_printf.h"

int main () {
   int t;
   int *p;
   char *arr;
   int re_value;

   t = -5;
   arr = "hello!!";

   re_value = ft_printf("le mine: %d%s%p\n",t, arr ,&t);
   printf("return :%d\n", re_value);
   re_value = printf("le mine: %s%d%p\n", arr,t ,&t);
   printf("return :%d\n", re_value);
    //printf("original printf :%.5d\n", t);

    // char *str = "%p %p %p\n";
    // int moi = ft_printf(str, "", "Hello", NULL);
    // printf("Result : %d\n\n", moi);

    // int vrai = printf(str, "", "Hello", NULL);
    // printf("Result : %d\n", vrai);

   return 0;
}