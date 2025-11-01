#include <stdio.h>

int main() {
    int even[5]; // Array to store even numbers (2, 4, 6, 8, 10)
    int odd[5];  // Array to store odd numbers (1, 3, 5, 7, 9)
    int evenCount = 0;
    int oddCount = 0;

    printf("Splitting natural numbers from 1 to 10 into even and odd:\n");

    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            even[evenCount] = i;
            evenCount++;
        } else {
            odd[oddCount] = i;
            oddCount++;
        }
    }

    printf("Even numbers: ");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("Odd numbers: ");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}