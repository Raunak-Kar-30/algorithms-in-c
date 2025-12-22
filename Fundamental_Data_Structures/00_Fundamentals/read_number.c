// Simple program to read the number from a string and return it's value

#include <stdio.h>
#include <string.h>

int string_to_num(char *number);

int main(void)
{
    char number[100];
    scanf("%s", number);

    int num = string_to_num(number);

    printf("%d\n", num);

    return 0;
}

int string_to_num(char *number)
{
    int len = strlen(number);

    if(number[len-1] == '\n')
    {
        number[len-1] = '\0';
        len = len - 1;
    }

    int num;

    for(int i = 0; i < len; i++)
    {
        int digit = (int) (number[i]) - 48;
        num = (num*10) + digit;
    }

    return num;
}