/* Simple implementation of tee unix command.

Text from standard input is put in a file and printed to standard out.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *in = fopen(argv[1], "w");
    char buffer[100];
    printf("Input:\n");
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(in, buffer);
    printf("\nSaved:\n%s", buffer);
    return 0;
}

/*
Question Answers

3. This implementation is very simple. If I were to work on it further
I would add complexity like handling multiple files.

4. The main difference I see is that the professional solutions have
error handling.
*/
