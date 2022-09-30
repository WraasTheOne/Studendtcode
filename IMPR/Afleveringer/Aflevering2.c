#include <stdio.h>

int main(void)
{

    int a, b, i, mindst;

    printf("Indtast to tal\n");
    scanf("%d %d", &a, &b);

    // jeg vil først sikre mig at programmet ved hvilket tal der er mindst
    if (a >= b)
    {
        mindst = b;
    }
    else
    {
        mindst = a;
    }

    if (a % b == 0)
    {
        printf("%d er den største fælles devisor", b);
    }
    else
    {
        for (i = mindst; i >= 0; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                printf("Har fundet en fælles divisor, og det er %d\n", i);
            }
        }
    }

    return 0;
}