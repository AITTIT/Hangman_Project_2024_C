#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>


const int gameover = 6;

void flushInputBuffer();
void hangmanDraw(int);

int main() {

    srand(time(NULL));
    char choice; 
    
    
   do {
        char user_letter;
        int right_letters = 0, wrong_guesses = 0, index = 0;
        char right_word[][12] = {"imaginary", "astronaut", "ship", "steam", "shovel", "goon", "hangman", "wild", "sarcasm", "posse"}; 
        int right_word_index = rand() % 10;
        
        //checkki jolla näkee minkä sanan random valitsee.
        printf("%d\n", right_word_index);

        int word_length = strlen(right_word[right_word_index]);
        char guessed_word[word_length];
        
        //assigns the guessed word letters with an underscore and prints them so the user sees the length of the word.
        for (int i = 0; i < word_length; i++) {
            guessed_word[i] = '_';
            printf("%c", guessed_word[i]);
        }

        /* A loop that is exited only when the player wins or loses. if the counter right_letters matches the word_length, the user
        has guessed the word and wins. If the counter wrong_guesses is no longer smaller than the integer stored in gameover,
        the game is over. */
        while (right_letters < word_length && wrong_guesses < gameover) {

            bool wrong_letter = true;
            bool already_guessed = false;
            //bool already_in_the_word = false;
            char guessed_letters[10];


            //Prompts the user to give a letter, reads it with scanf, then empties the buffer in case more letters than one were given.
            printf("\nGuess a letter\n");
            scanf("%c", &user_letter);
            flushInputBuffer();

            //check että näkee että input on tallentunu oikeen.
            printf("\n%c\n", user_letter);

             
             //Compares the user input to an array of guessed letters. If the read letter matches, already_guessed true.
             //Compares the user input to the guessed word. If there is a match, already_in_the_word is true. 
            for ( int i = 0; i < index ; i++) {
                if (user_letter == guessed_letters[i]) {
                    already_guessed = true;
                }
                /*
                if (user_letter == guessed_word[i]) {
                    already_in_the_word = true;
                }
                */
            }

            /* Jos ohjelma ei ole käynyt kummassakaan ylemmässä if lauseessa, ja molemmat booleanit ovat edelleen
            arvoltaan false, tähän iffiin mennään ja käyttäjän antama kirjain lisätään arvattuihin kirjaimiin.
            Sen jälkeen indexiin lisätään yksi, jolloin seuraava uusi kirjain lisätään seuraavaan paikkaan.d,sa.mf.,dmas
            */
            if (already_guessed == false) {
                guessed_letters[index] = user_letter;
                index++;
            }
                
            //miksi ihmeessä tää on for loopissa?
            for (int i = 0; i < word_length ; i++) { 
                if (already_guessed == true)  { 
                    printf("\nYou have guessed that already."); 
                    already_guessed = true;
                }
            }

            printf("\nGuessed letters: ");
            for (int i = 0; i < index ; i++) {
                printf(" %c", guessed_letters[i]);
            }
            

            if (already_guessed == false) {            
                for (int i = 0; i < word_length ; i++) {
                    if (user_letter == right_word[right_word_index][i]) {
                        guessed_word[i] = right_word[right_word_index][i];
                        right_letters++;
                        wrong_letter = false;
                    }
                }
            }

           
            if (already_guessed == false) {    
                if (wrong_letter == false) {
                    printf("\nYou guessed right!");
                }
                if (wrong_letter == true) {
                    printf("\nYou guessed wrong.");
                    wrong_guesses++; 
                } 
            }
            printf("\n");
            for (int i = 0; i < word_length ; i++) {
                printf("%c", guessed_word[i]);
            }
            hangmanDraw(wrong_guesses);
        
        }

        if (right_letters == word_length) {
            printf("\nWell done! Do you want to play again?(y/n)");
        } else {
            printf("\nTough luck, you lost! Do you want to play again?(Y/N)");
        }
        scanf("%c", &choice);
        flushInputBuffer();

    } while (choice != 'n');

    return 0;
}



void flushInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void hangmanDraw(int wrong_guesses) {

    

    switch (wrong_guesses)
    {
    case 0:
        printf("\n   _____");
        printf("\n  |     |");
        printf("\n  |      ");
        printf("\n  |      ");
        printf("\n  |      ");
        printf("\n__|___________");
        break;
    case 1:
        printf("\n   _____");
        printf("\n  |     |");
        printf("\n  |     O");
        printf("\n  |      ");
        printf("\n  |      ");
        printf("\n__|___________");
        break;
    case 2:
        printf("\n   _____");
        printf("\n  |     |");
        printf("\n  |     O");
        printf("\n  |     |");
        printf("\n  |      ");
        printf("\n__|___________");
        break;
    case 3:
        printf("\n   _____");
        printf("\n  |     |");
        printf("\n  |    \\O");
        printf("\n  |     |");
        printf("\n  |      ");
        printf("\n__|___________");
        break;
    case 4:
        printf("\n   _____");
        printf("\n  |     |");
        printf("\n  |    \\O/");
        printf("\n  |     |");
        printf("\n  |      ");
        printf("\n__|___________");
        break;
    case 5:
        printf("\n   _____");
        printf("\n  |     |");
        printf("\n  |    \\O/");
        printf("\n  |     |");
        printf("\n  |    / ");
        printf("\n__|___________");
        break;
    case 6:
        printf("\n   _____");
        printf("\n  |     |");
        printf("\n  |    \\O/");
        printf("\n  |     |");
        printf("\n  |    / \\");
        printf("\n__|___________");
        break;
            
    default:
        printf("\nSomething went wrong.");
        break;
    }

}

//Pitäisikö vielä kerran yrittää sitä etteivät oikeat kirjaimet tulisi guessed letter listaan? Testaa commit