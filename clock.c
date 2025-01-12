#include <stdio.h>
#include <time.h>
#include <unistd.h> 

void displayClock(int format) {
    while (1) {
        time_t raw_time;
        struct tm *current_time;
        char time_buffer[50];
        char date_buffer[50];

        // Get the current raw time
        time(&raw_time);
        current_time = localtime(&raw_time);

        // Format time based on user choice
        if (format == 1) {
            strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", current_time); // 24-hr
        } else {
            strftime(time_buffer, sizeof(time_buffer), "%I:%M:%S %p", current_time); // 12-hr
        }

        // Format the date
        strftime(date_buffer, sizeof(date_buffer), "%A %B %d %Y", current_time);

        // Clear the screen
#ifdef _WIN32
        system("cls"); // Clear screen for Windows
#else
        system("clear"); // Clear screen for Linux/Mac
#endif

        // Display the time and date
        printf("Current Time: %s\n", time_buffer);
        printf("Date: %s\n", date_buffer);

        // Pause for sec
        sleep(1);
    }
}

int main() {
    int choice;

    printf("Choose the time format:\n");
    printf("1. 24 Hour format\n");
    printf("2. 12 Hour format (default)\n");
    printf("Make a choice (1/2): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        choice = 2;
    }
    
    displayClock(choice);

    return 0;
}