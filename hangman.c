#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//The amount of guessed letters that are not in the right word before game over.
const int gameover = 6;

void flushInputBuffer();
void hangmanDraw(int);

int main() {

    // seeds the random number generator.
    srand(time(NULL)); 
    //saves the users answer about whether they want to continue playing or not.
    char game_continue_choice; 
    
    // A do-while that runs as long as the contents of variable game_continue_choice is something other than 'n'.
   do {
        //The user input is saved into this.
        char user_letter;

        int right_letters = 0, wrong_guesses = 0;

        // A two dimensional array containing words that are then chosen randomly with the help of right_word_index.
        char right_word[][12] = {"imaginary", "astronaut", "ship", "steam", "shovel", "goon", "hangman", "wild", "sarcasm", "posse"}; 
        int right_word_index = rand() % 10;
        

        //Variable that has the length of the chosen right word saved.
        int word_length = strlen(right_word[right_word_index]);
        // A char array that is given the same length as the right word.
        char guessed_word[word_length];
        // A char array where the guessed letters will be saved into.
        char guessed_letters[26];
        // guessed_letters_index keeps tally on the amount of actual letters saved inside guessed_letters
        int guessed_letters_index = 0;
        
        // Loop that saves an underscore into every space in the char array guessed_word.
        // Also prints out the underscores for the user to see the length of the word.
        for (int i = 0; i < word_length; i++) {
            guessed_word[i] = '_';
            printf("%c", guessed_word[i]);
        }

        /* A loop that is exited only when the user wins or loses. if the counter right_letters matches the word_length, the user
        has guessed the word and wins. If the counter wrong_guesses is no longer smaller than the integer stored in gameover,
        there have been too many wrong guesses and the game is over. */
        while (right_letters < word_length && wrong_guesses < gameover) {

            bool wrong_letter = true;
            bool already_guessed = false;

            //Prompts the user to give a letter, reads it with scanf, then empties the buffer in case more characters than one were given.
            // If the user does not give a lowercase letter, loops back.
            printf("\nGuess a letter\n");
            do {
                scanf("%c", &user_letter);
                flushInputBuffer();
                if (isalpha(user_letter) != 2) {
                    printf("Please enter a lowercase letter.\n");
                }
            } while (isalpha(user_letter) != 2);

             //Compares the user input to the array of already guessed letters. If there is a match, already_guessed true. 
            for ( int i = 0; i < guessed_letters_index ; i++) {
                if (user_letter == guessed_letters[i]) {
                    already_guessed = true;
                }
            }

            // If the already_guessed boolean has stayed false, the user_letter is saved into guessed_letters array
            // and the index is incremented by one.
            if (already_guessed == false) {
                guessed_letters[guessed_letters_index] = user_letter;
                guessed_letters_index++;
            }
            

            
            //Prints out the letters that have already been guessed.
            printf("\nGuessed letters: ");
            for (int i = 0; i < guessed_letters_index ; i++) {
                printf(" %c", guessed_letters[i]);
            }

            //If already_guessed has become true, informs the user the following.
            if (already_guessed == true)  { 
                printf("\nYou have guessed that already."); 
            }
            
            //If already_guessed has stayed false, compares the user_letter to the right_word array. 
            // If there is a match, the user_letter is saved into the guessed_word,
            //and it replaces the underscore. right_letters counter is incremented by one,
            // and the boolean wrong_letter becomes false.
            if (already_guessed == false) {            
                for (int i = 0; i < word_length ; i++) {
                    if (user_letter == right_word[right_word_index][i]) {
                        guessed_word[i] = user_letter;
                        right_letters++;
                        wrong_letter = false;
                    }
                }
            }

           //Entered only if the user input is new and already_guessed has stayed false.
            if (already_guessed == false) {    
                //if wrong_letter has turned false, "you guessed right!" is printed,
                // otherwise "You guessed wrong.", and the wrong_guesses counter is incremented by one.
                if (wrong_letter == false) {
                    printf("\nYou guessed right!");
                } else {
                    printf("\nYou guessed wrong.");
                    wrong_guesses++; 
                } 
            }
            printf("\n");
            //Prints the guessed word with possible new letters.
            for (int i = 0; i < word_length ; i++) {
                printf("%c", guessed_word[i]);
            }
            //Calls the hangman function that draws the picture of the hangman.
            hangmanDraw(wrong_guesses);
        }

        //If right_letters matches word_length when the above while-loop is exited,
        // the user has won. Else the user has lost.
        //scan function that takes user input, then flusInputBuffer() function to empty the buffer.
        if (right_letters == word_length) {
            printf("\nWell done! Do you want to play again?(y/n)");
        } else {
            printf("\nTough luck, you lost! Do you want to play again?(y/n)");
        }
        scanf("%c", &game_continue_choice);
        flushInputBuffer();
        //Program is exited, if the user has entered 'n', otherwise loop back to start.
    } while (game_continue_choice != 'n');

    return 0;
}


//function that is used after scanf to empty the input buffer in case
// the user has entered more than one letter.
void flushInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//function that draws the hangman. Depending on the value of wrong_guesses variable,
//switch case chooses which iteration of the hangman is printed.
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