
//C program to convert roman numbers into decimal

#include <stdio.h>
#include <string.h>

int convert(char);

int solve()
{
    int i = 0, num = 0;
    char romanNumber[100];

    // printf("Enter Roman number: ");
    scanf("%s", romanNumber);

    while (romanNumber[i])
    {

        if (convert(romanNumber[i]) < 0)
        {
            printf("\nInvalid Roman Number.\n");
            return 0;
        }

        if ((strlen(romanNumber) - i) > 2)
        {
            if (convert(romanNumber[i]) < convert(romanNumber[i + 2]))
            {
                printf("\nInvalid Roman Number.\n");
                return 0;
            }
        }

        if (convert(romanNumber[i]) >= convert(romanNumber[i + 1]))
            num = num + convert(romanNumber[i]);
        else
        {
            num = num + (convert(romanNumber[i + 1]) - convert(romanNumber[i]));
            i++;
        }
        i++;
    }
    return num;
}

int main()
{
    printf("Enter the first number\n");
    int a = solve();
    printf("enter the second number\n");
    int b = solve();

    int num = a + b;
     printf("The result is :");
    while (num != 0)
    {

        if (num >= 1000) // 1000 - m
        {
            printf("M");
            num -= 1000;
        }

        else if (num >= 900) // 900 -  cm
        {
            printf("CM");
            num -= 900;
        }

        else if (num >= 500) // 500 - d
        {
            printf("D");
            num -= 500;
        }

        else if (num >= 400) // 400 -  cd
        {
            printf("CD");
            num -= 400;
        }

        else if (num >= 100) // 100 - c
        {
            printf("C");
            num -= 100;
        }

        else if (num >= 90) // 90 - xc
        {
            printf("XC");
            num -= 90;
        }

        else if (num >= 50) // 50 - l
        {
            printf("L");
            num -= 50;
        }

        else if (num >= 40) // 40 - xl
        {
            printf("XL");
            num -= 40;
        }

        else if (num >= 10) // 10 - x
        {
            printf("X");
            num -= 10;
        }

        else if (num >= 9) // 9 - ix
        {
            printf("IX");
            num -= 9;
        }

        else if (num >= 5) // 5 - v
        {
            printf("V");
            num -= 5;
        }

        else if (num >= 4) // 4 - iv
        {
            printf("IV");
            num -= 4;
        }

        else if (num >= 1) // 1 - i
        {
            printf("I");
            num -= 1;
        }
    }

    return 0;
}

int convert(char ch)
{
    int value = 0;

    switch (ch)
    {
    case 'I':
        value = 1;
        break;
    case 'V':
        value = 5;
        break;
    case 'X':
        value = 10;
        break;
    case 'L':
        value = 50;
        break;
    case 'C':
        value = 100;
        break;
    case 'D':
        value = 500;
        break;
    case 'M':
        value = 1000;
        break;
    case '\0':
        value = 0;
        break;
    default:
        value = -1;
    }
    return value;
}
