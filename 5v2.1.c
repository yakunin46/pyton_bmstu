#include <stdio.h>

#define N 10

void main_code(const int (*matrix_A)[N],const int (*matrix_B)[N],int rows){

    float sum_B=0;
    float sum_A=0;
    int flag=1;
    for (int i=0;i<N;i++){
        sum_A+=matrix_A[i][i];
        sum_B+=matrix_B[i][i];
    }
    if (sum_A>=sum_B){
        flag=1;
    }
    else{
        flag=0;
    }
    printf("flag = %d",flag);
}

int main(void){
    int count=0;
    int matrix_A[N][N]={0};
    int matrix_B[N][N]={0};

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            matrix_A[i][j]=count; 
        ++count;
    }

    --count;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            matrix_B[i][j]=count; 
        --count;
    }

    // int sum_diagonalA = 0;
    // int sum_diagonalB = 0;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (i == j) 
    //         { 
    //             sum_diagonalA += matrix_A[i][j]; // Добавление элемента к сумме
    //         }
    //     }
    // }
    // for (int i = 0; i < N; i++) 
    // {
    //         for (int j = 0; j < N; j++) 
    //         {
    //             if (i == j) 
    //             { 
    //                 sum_diagonalB += matrix_B[i][j]; // Добавление элемента к сумме
    //             }
    //         }
    //     }
    // if (sum_diagonalA>=sum_diagonalB)
    // {
    //     flag=1;
    // }
    // else
    // {
    //     flag=0;
    // }
    // printf("flag = %d",flag);
    



    main_code(matrix_A,matrix_B,N);
}