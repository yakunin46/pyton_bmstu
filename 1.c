#include <stdio.h>


int main1() {
    float x = 2.5;
    int y = 10;
    int z;
    z = x++ * --y + y / x;
    printf("\nmain1\n");
    printf("%.2f\n", (float)z);
    return 0;
}

int main2(){
    char a = 'A';
    int b = 3;
    int result;
    result = a++ * --b + b % a;
    printf("\nmain2\n");
    printf("%c\n", (char)result);
    return 0;
}

int main3(){
    double m = 10.5;
    int n = 7;
    int p;
    p = ++n * m-- - n + m;
    printf("\nmain3\n");
    printf("%.3f\n", (double)p);
    return 0;
}


int main4(){
    short int p = 15;
    long int q = 100;
    long int r;
    r = --p * ++q - q / p;
    printf("\nmain4\n");
    printf("%ld\n", r);
    return 0;
}

int main5(){
    unsigned int x = 8;
    unsigned int y = 4;
    unsigned int z;
    z = x++ * --y + x % y;
    printf("\nmain5\n");
    printf("%u\n", z);
    return 0;
}

int main6(){
    int x = 4;
    int y = 32;
    int c;
    c = -x-- * ++y - x + y;
    printf("\nmain6\n");
    printf("%7.5d\n", c);
    return 0;
}

int main(){
    main1();
    main2();
    main3();
    main4();
    main5();
    main6();
    return 0;

}
