/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void int_address(int x){
    printf("The address is: %p\n", &x);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(2);
    void *v = malloc(14);
    char *s = "Hello, World";
    
    int_address(var2);
    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("v points to %p\n", v);
    printf ("s points to %p\n", s);

    return 0;
}
