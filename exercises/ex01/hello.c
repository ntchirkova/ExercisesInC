#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("Here is y: %d\n", y);
    return 0;
}

/* I was not able to compile with optimization. 
I went to ninja hours and they were not able to help me.

It compiles when I run: gcc hello.c -o -v hello && ./hello
But it has a linker error when I run: gcc hello.c -O2 -v hello && ./hello
*/