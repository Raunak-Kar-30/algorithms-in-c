// Find the prime numbers using sieve of eratosthenes method

#include <stdio.h>

int main(void)
{
    int n;
    printf("Range from 0 to : ");
    scanf("%d", &n);

    int prime_array[n+1];
    int i = 0;

    // Set all the values to 1
    for(prime_array[0] = 0, prime_array[1] = 0, i = 2; i < n; i++) prime_array[i] = 1;

    // Every single index value of the prime_array[] whose factors are from 2->n/2 are set to 0
    // For that we first run a loop for each factor i to n/2 and whatever is the result of i*j we set value at the index to 0 
    for(int i = 2; i <= n/2; i++)
    {
        printf("Hello\n");
        for(int j = 2; j <= n/i; j++)
        {
            prime_array[i*j] = 0;
        }
    }

    for(int i = 0; i <= n; i++) 
    {
        if(prime_array[i] == 1) printf("%d ", i);
    }
    printf("\n");

    return 0;
}