#include <stdio.h>

int main(){

    float a=1, b=3, c=2.25, d, v,vn,x1=0,x2;
    int flag=1,count;
    printf("Enter the coefficients of the quadratic equation\n");
    printf("Input format: a;b;c\n");

    printf(">>>");
    // scanf("%f;%f;%f",&a,&b,&c);

    if (a==0)
    {
        printf("Not a quadratic equation\n");
    }

    else
    {
        d=(b*b)-(4*a*c);
        if (d>0)
        {
            count=2;
        }
        if (d==0)
        {
            count=1;
        }
        if (d<0)
        {
            count=0;
            printf(">>>No solutions\n");
        }
    }
    v=a*x1*x1+b*x1+c;
    if (count=1){
        if (v<0){
            while (v<0){
                x1+=1;
                vn=a*x1*x1+b*x1+c;
                // if (v>vn){
                //     x1=0;
                //     break;
                // }
                
                v=vn;
                
            }

            
        }
    


        if (v>0){
            while (v>0){
                x1+=1;
                vn=a*x1*x1+b*x1+c;
                // printf("%f %f ",v,vn);
                if (vn>v){
                    x1=0;
                    break;
                }
                else{
                    v=vn;
                }
            }

            v=a*x1*x1+b*x1+c;
            if (x1==0){
                while (v>0){
                    x1-=1;
                    v=a*x1*x1+b*x1+c;
                    printf("%f\n",v);
                }
            }
        }
    }
    printf("%f %f %f\n",a,b,c);
    printf("%f %f %f",x1,d,v);
    return 0;
}
