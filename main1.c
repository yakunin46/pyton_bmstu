#include <stdio.h>
#include <stdlib.h>

float koren(float(a))
{
    float i,b;
    float k,k1,k2;
    for (i=1;i<=a/2;i++)
    {
        if (i*i>a)
        {
            k=a/(i-1);
            k1=(k+(i-1))/2;
            k2=a/k1;
            b=(k1+k2)/2;
            break;
        }
    }
   return b;
}


int main()
{
    float a,b,c,d,kd=1,x1,x2;

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
        kd=koren(d);
        if (d>0)
        {
            x1=(-b-kd)/(2*a);
            x2=(-b+kd)/(2*a);
            printf(">>>x1=%f\n>>>x2=%f",x1,x2);
        }
        if (d==0)
        {
            x1=(-b)/(2*a);
            printf(">>>x1=x2=%f",x1);
        }
        if (d<0)
        {
            printf(">>>No solutions\n");
        }
    }

    return 0;
}
