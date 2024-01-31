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
    do {
        scanf("%c", &user_letter);
        flushInputBuffer();

        
    } while (isalpha(user_letter) != 1);

    printf("%c", user_letter);





    return 0;
}


void flushInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}