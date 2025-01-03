#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>  
#include <time.h>   

#define MAX_QUESTIONS 5 
#define TIME_LIMIT 15 

typedef struct {
    char question[256];  
    char options[4][100];
    char correct_option;
    int prize_money;       
} Question;

// Function to load all the questions and their corresponding details
void loadQuestions(Question questions[]) {

    // Question 1
    strcpy(questions[0].question, "Who is the founder of Microsoft?");
    strcpy(questions[0].options[0], "A. Steve Jobs");
    strcpy(questions[0].options[1], "B. Bill Gates");
    strcpy(questions[0].options[2], "C. Mark Zuckerberg");
    strcpy(questions[0].options[3], "D. Larry Page");
    questions[0].correct_option = 'B';
    questions[0].prize_money = 1000;

    // Question 2
    strcpy(questions[1].question, "Which planet is known as the Red Planet?");
    strcpy(questions[1].options[0], "A. Earth");
    strcpy(questions[1].options[1], "B. Venus");
    strcpy(questions[1].options[2], "C. Mars");
    strcpy(questions[1].options[3], "D. Jupiter");
    questions[1].correct_option = 'C';
    questions[1].prize_money = 2000;

    // Question 3
    strcpy(questions[2].question, "What is the capital of France?");
    strcpy(questions[2].options[0], "A. Berlin");
    strcpy(questions[2].options[1], "B. Madrid");
    strcpy(questions[2].options[2], "C. Paris");
    strcpy(questions[2].options[3], "D. Rome");
    questions[2].correct_option = 'C';
    questions[2].prize_money = 3000;

    // Question 4
    strcpy(questions[3].question, "What is the largest ocean on Earth?");
    strcpy(questions[3].options[0], "A. Atlantic Ocean");
    strcpy(questions[3].options[1], "B. Indian Ocean");
    strcpy(questions[3].options[2], "C. Arctic Ocean");
    strcpy(questions[3].options[3], "D. Pacific Ocean");
    questions[3].correct_option = 'D';
    questions[3].prize_money = 4000;

    // Question 5
    strcpy(questions[4].question, "Who wrote 'Romeo and Juliet'?");
    strcpy(questions[4].options[0], "A. Charles Dickens");
    strcpy(questions[4].options[1], "B. William Shakespeare");
    strcpy(questions[4].options[2], "C. Jane Austen");
    strcpy(questions[4].options[3], "D. Mark Twain");
    questions[4].correct_option = 'B';
    questions[4].prize_money = 5000;
}

// Function to play the KBC game
void playGame(Question questions[]) {

    int total_prize = 0;

    printf("\nWelcome to Kaun Banega Crorepati (KBC)!\n");
    printf("-----------------------------------\n\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {

        printf("Question %d: %s\n\n", i + 1, questions[i].question);

        // Display the options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }

        printf("\nPrize for this question: $%d\n", questions[i].prize_money);
        printf("You have %d seconds to answer.\n\n", TIME_LIMIT);

        // Capture start time
        time_t start_time = time(NULL);
        char answer;
        printf("Enter your answer (A, B, C, D): ");
        scanf(" %c", &answer);

        // Capture end time
        time_t end_time = time(NULL);

        // Check if the answer was within the time limit
        if (difftime(end_time, start_time) > TIME_LIMIT) {
            printf("\nTime's up! You failed to answer in time.\n\n");
            break;
        }

        // Validate the answer
        if (toupper(answer) == questions[i].correct_option) {
            printf("\nCorrect! You won $%d.\n\n", questions[i].prize_money);
            total_prize += questions[i].prize_money;
        } else {
            printf("\nWrong! The correct answer was %c.\n\n", questions[i].correct_option);
            break;
        }
    }

    // Display total winnings
    printf("-----------------------------------\n");
    printf("\nYou won a total of $%d.\n", total_prize);

    // Final message based on performance
    if (total_prize == 15000) {
        printf("Congratulations! You are a Crorepati!\n");
    } else if (total_prize >= 5000) {
        printf("Well done! You performed well.\n");
    } else {
        printf("Better luck next time!\n");
    }
}

int main() {

    Question questions[MAX_QUESTIONS];

    loadQuestions(questions);

    playGame(questions);

    return 0;
}
