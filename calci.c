#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menu() {
    printf("\n-------- Simple Calculator--------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
}

void add() {
    int n;
    double num, sum = 0;

    printf("How many numbers? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%lf", &num);
        sum += num;
    }

    printf("Sum = %.2f\n", sum);
}

void subtract() {
    int n;
    double num, result;

    printf("How many numbers? ");
    scanf("%d", &n);

    printf("Enter number 1: ");
    scanf("%lf", &result);

    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%lf", &num);
        result -= num;
    }

    printf("Result = %.2f\n", result);
}

void multiply() {
    int n;
    double num, result = 1;

    printf("How many numbers? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%lf", &num);
        result *= num;
    }

    printf("Product = %.2f\n", result);
}

void divide() {
    int n;
    double num, result;

    printf("How many numbers? ");
    scanf("%d", &n);

    printf("Enter number 1: ");
    scanf("%lf", &result);

    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%lf", &num);

        if (num == 0) {
            printf("Error: Division by zero!\n");
            return;
        }

        result /= num;
    }

    printf("Result = %.2f\n", result);
}

void modulus() {
    int a, b;

    printf("Enter first number A: ");
    scanf("%d", &a);
    printf("Enter second number B: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("Error: Division by zero!\n");
        return;
    }

    printf("Remainder = %d\n", a % b);
}

void power() {
    double base, exp;

    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%lf", &exp);

    printf("Result = %.2f\n", pow(base, exp));
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Choose an option : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: modulus(); break;
            case 6: power(); break;
            case 7: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}