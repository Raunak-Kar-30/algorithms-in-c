// Program to implement the gcd of 3 numbers using euclid's method
// gcd(a,b,c) = gcd(a,gcd(b,c))

#include <stdio.h>

int euclid_gcd(int a, int b);

int main(void)
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    int gcd = euclid_gcd(a,euclid_gcd(b,c));
    printf("%d\n", gcd);

    return 0;
}

int euclid_gcd(int a, int b)
{
    int temp = 0;
    while(a > 0)
    {
        if(a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }

        a = a - b;
    }

    return b;
}