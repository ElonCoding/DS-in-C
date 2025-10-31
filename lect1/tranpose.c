#include <stdio.h>

int main() {
    int matrix[3][3];
    
    printf("Enter 9 elements:\n");
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("\nOriginal Matrix:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    
    printf("\nTranspose Matrix:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            printf("%d ", matrix[j][i]);
        printf("\n");
    }
    
    return 0;
}
