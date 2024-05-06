#include <stdio.h>

int main1(){

int a =16, b=20, c;
c=a-- * ++b -a + b;
printf("%07d",c);
}

int main2(){

int a=0546, b=911, c=0x0a72;
printf("%7.5d%7.5x%7.5d",a,b,c);
}

#define n 2

int main3(){

    int matrix_A[n][n]={1,2,3,4};
    int matrix_B[n][n]={1,2,3,4};
    int sum_A=0;
    int sum_B=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            sum_A+=matrix_A[i-1][j-1]; /* !!! */
            sum_B+=matrix_B[i-1][j-1]; /* !!! */
            printf("%d %d ",matrix_A[i-1][j-1],matrix_B[i-1][j-1]);
        }
    }
    printf("%d %d",sum_A,sum_B);
}

int main(){
    main1();
    printf("\n");
    main2();
    printf("\n");
    main3();

    return 0;

}