// Program to implement the decimal to binary conversion

#include <stdio.h>

int dec_to_bin(int decimal);
int power(int base, int exp);

int main(void)
{
    int decimal = 0;
    scanf("%d", &decimal);

    printf("%d\n", dec_to_bin(decimal));

    return 0;
}

int dec_to_bin(int decimal)
{
    int binary = 0;
    int i = 0;

    while(decimal > 0)
    {
        int rem = decimal % 2;
        decimal  = decimal / 2;

        binary = binary + rem * power(10,i);
        i = i + 1;
    }

    return binary;
}

int power(int base, int exp)
{
    int power = 1;
    for(int i = 0; i < exp; i++)
    {
        power = power * base;
    }

    return power;
}