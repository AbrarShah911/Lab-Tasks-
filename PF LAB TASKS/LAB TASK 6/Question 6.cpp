#include <stdio.h>

int main() {
    int n;

    printf("Please enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; 
    }

    int a = 0, b = 1; 

    for (int i = 1; i <= n; i++) {
        printf("%d ", a); 
        int next = a + b; 
        a = b;            
        b = next;        
    }

    printf("\n");

    return 0;
}