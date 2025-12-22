// This program implements euclid's another way of calculating the GCD of two numbers
// Where GCD of a and b is the same as the GCD of b and b%a

#include <stdio.h>

int modulo_gcd(int a, int b);

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", modulo_gcd(a,b));

    return 0;
}

int modulo_gcd(int a, int b)
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

        a = a % b;
    }

    return b;
}