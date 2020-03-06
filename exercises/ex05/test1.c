#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand.h"

int main (int argc, char *argv[])
{
    int i;
    float x;

    srandom (time (NULL));

    for (i=0; i<10000; i++) {
        x = random_float();
        printf ("%lf\n", x);
    }
    return 0;
}