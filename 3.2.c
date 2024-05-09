#include <stdio.h>

#define SIZE 2

void main_code(const int (*matrix_A)[SIZE],const int (*matrix_B)[SIZE],int rows){
    float sum_B=0;
    float sum_A=0;
    float sum_AB_k=0;
    float result=0;
    float vector_C[SIZE]={0};

    for (int i=0;i<SIZE;i++){
            for (int j=0;j<SIZE;j++){ 
                sum_B+=matrix_B[j][i];
                sum_A+=matrix_A[i][j];
            }
            for (int k=0;k<SIZE;k++){
                sum_AB_k+=matrix_A[k][k]*matrix_B[k][k];
            }
        result=sum_B-sum_A/sum_AB_k;
        vector_C[i]=result;
    }

    printf("Вектор C: ");

    for (int i=0; i<SIZE; i++){
        printf("%f ",vector_C[i]);
    }
}

int main(void){
    int count=0;
    int matrix_A[SIZE][SIZE]={0};
    int matrix_B[SIZE][SIZE]={0};

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix_A[i][j]);
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix_B[i][j]);
        }
    }

    main_code(matrix_A,matrix_B,SIZE);
}