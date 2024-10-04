#include <stdio.h>

int main() {
    int newNumber, number, r1, r2 = 0;

    printf("Please enter a number: ");
    scanf("%d", &newNumber);

    number = newNumber;


    while (newNumber != 0) {
        r1 = newNumber % 10; 
        r2 += r1 * r1 * r1; 
        newNumber /= 10; 
    }


    if (r2 == number) {
        printf("%d is an Armstrong number.\n", number);
    }else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
