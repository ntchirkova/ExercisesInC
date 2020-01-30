/*
Card game that counts cards based on their values.

Nina Tchirkova
*/

#include <stdio.h>
#include <stdlib.h>

/* Gets name of card based on user input.

   Returns char of card name.
*/
char get_card_name() {
    char card[3];
    puts("Enter the card name: ");
    scanf("%2s", card);
    return card[0];
}

/* Identifies value of card based on its name.

   card_name: char of card name.

   Returns card name value as int.
*/
int card_to_value(char card_name) {
    int val = 0;
    switch(card_name) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            break;
        default:
            val = card_name - '0'; // why is this possible
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
            }
    }
    return val;
}

/* Updates count in the card game.

    count: int of count from last state.
    val: card value as int.

    Returns updated count.
*/
int count_cards(int count, int val) {
    if ((val > 2) && (val <7)) {
        count++;
    } else if (val == 10) {
        count--;
    }
    return count;
}

int main () {
    char card_name;
    int count = 0;

    do {
        card_name = get_card_name();
        count = count_cards(count, card_to_value(card_name));
        printf("Current count: %i\n", count);
    } while (card_name != 'X');

    return 0;
}