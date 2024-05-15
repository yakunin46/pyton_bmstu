#include <stdio.h>
const double eps = 10e-14;

double solute(float a, float b, float c){
    double x = 1; 
    while (a*x*x+b*x+c > eps ||  a*x*x+b*x+c < -eps){
        x = x - ((a*x*x+b*x+c) / (2*a*x+b));
    }
    return x;
}

float main(){
    float a, b, c, d, x1;

    printf("Enter the coefficients of the quadratic equation\n");
    printf("Input format: a;b;c\n");

    printf(">>>");
    scanf("%f;%f;%f",&a,&b,&c);

    if (a==0)
    {
        printf("Not a quadratic equation\n");
    }
    
    else
    {
        d=(b*b)-(4*a*c);
        if (d>0)
        {
            x1=solute(a,b,c);
            printf(">>>x1=%f\n>>>x2=%f",x1,-b/a-x1);
        }
        if (d==0)
        {
            x1=solute(a,b,c);
            printf(">>>x1=x2=%f",x1);
        }
        if (d<0)
        {
            printf(">>>No solutions\n");
        }
    }
}