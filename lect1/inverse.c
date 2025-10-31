#include <stdio.h>

void getMatrix(float matrix[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

void findInverse(float matrix[3][3], float inverse[3][3]) {
    float det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
                matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) +
                matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    
    float invDet = 1.0f / det;
    
    // Calculate inverse
    inverse[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) * invDet;
    inverse[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * invDet;
    inverse[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) * invDet;
    inverse[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * invDet;
    inverse[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * invDet;
    inverse[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) * invDet;
    inverse[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * invDet;
    inverse[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) * invDet;
    inverse[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) * invDet;
}

int main() {
    float matrix[3][3], inverse[3][3], sum[3][3];

    printf("Enter the elements of 3x3 matrix:\n");
    getMatrix(matrix);
    findInverse(matrix, inverse);

    // Add and print result
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum[i][j] = matrix[i][j] + inverse[i][j];
            printf("%.2f\t", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
