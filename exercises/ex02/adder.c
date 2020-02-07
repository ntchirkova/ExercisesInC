/* Nina Tchirkova

Program sums numbers input in terminal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Reads input from terminal. If input is too large or not
acceptible will stop program with error.

current: pointer to int that will hold the inputted number.

returns true if valid input and false if not.
*/
bool get_int(int *current) {
    char num[10];
    printf("Enter your number: \n");
    while((fgets(num, sizeof(num), stdin)) != NULL) {
        if (num[9] == '\n') {
            printf("your number was too large");
            fflush(stdin);
            break;
        } else {
            *current = atoi(num);
            if (*current == 0) {
                printf("Value must be an an integer larger than 0.");
                return false;
            }
            return true;
        }
    }
    return false;
}

/* Sums an array of ints.

arr: an array of ints.
size: the lenght of arr.

returns int representing sum.
*/
int array_sum(int arr[], int size){
    int i;
    int sum = 0;
    for (i=0; i<size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

int main () {
    int current_int;
    bool value_entered;
    int nums[100];
    int i = 0;
    while (i < 100) {
        value_entered = get_int(&current_int);
        if (value_entered) {
            nums[i] = current_int;
            i++;
        } else {
            break;
        }
    }
    printf("The sum is: %i\n", array_sum(nums, i+1));
    return 0;
}
