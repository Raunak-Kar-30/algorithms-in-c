// This program implements euclid's method for calculating GCD of two numbers
// It states that GCD of two numbers a and b is the same as the GCD of b and a-b
// Ultimately a becomes 0 and b gives the GCD

#include <stdio.h>

int euclid_gcd(int a, int b);

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n",euclid_gcd(a,b));

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

        a = a-b;
    }

    return b;
}