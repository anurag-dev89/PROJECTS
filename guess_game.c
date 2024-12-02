#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random, guess;
    int no_of_guess = 0;

    // Initialize random number generator with the current time as seed
    srand(time(NULL));
    random = rand() % 100 + 1;  // Generate a random number between 1 and 100

    // Welcome message
    printf("\n---- Welcome To The World Of Guessing Numbers ----\n");
    printf("* I am thinking of a number between 1 and 100.\n");
    printf("* Try to guess the number.\n");
    printf("* Let's start!\n");
    printf("* Enter your first guess.\n");

    do {
        printf("\nPlease Enter Your Guess Between 1 To 100: ");
        scanf("%d", &guess);
        no_of_guess++;

        if (guess < random) {
            printf("Your Guess Is Too Low.\n");
            printf("Try A Larger Number.\n");
        }else if (guess > random) {
            printf("Your Guess Is Too High.\n");
            printf("Try A Smaller Number.\n");
        }else {
            printf("Congratulations! You Guessed The Number In %d Attempts.\n", no_of_guess);
        }

    } while (guess != random);  // Continue until the correct guess

    printf("\nThanks For Playing! Goodbye.\n");
    printf("Developed by: Anurag\n");

    return 0;
}
