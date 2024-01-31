#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void flushInputBuffer();

int main() {

    char user_letter;

     printf("\nGuess a letter\n");
    //do {
        scanf("%c", &user_letter);
        flushInputBuffer();

    /*    if (isalpha(user_letter) == 0) {
            printf("Please enter a letter.\n");
        }
    */
        char letter = isalpha(user_letter);
        printf("%c", letter);
        
    //} while (isalpha(user_letter) != 1);

   // printf("%c", user_letter);





    return 0;
}


void flushInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}