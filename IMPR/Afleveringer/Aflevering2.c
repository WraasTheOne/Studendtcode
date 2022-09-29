#include <stdio.h>

int main(void)
{

    int a, b, i, mindst;

    printf("Indtast to tal\n");
    scanf("%d %d", &a, &b);

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
                printf("%d er den største fælles devisor", i);
                break;
            }
        }
    }

    return 0;
}