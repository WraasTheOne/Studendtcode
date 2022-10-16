#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int spiller_tal, tal_1, tal_2, tal_3;
    srand(time(NULL));

    do
    {
        printf("vælg et tal mellem 1 og 10\n");
        scanf("%d", &spiller_tal);

        tal_1 = (rand() % 10) + 1;
        tal_2 = (rand() % 10) + 1;
        tal_3 = (rand() % 10) + 1;

        printf("%d, %d, %d\n\n", tal_1, tal_2, tal_3);

        if (spiller_tal == tal_1 || spiller_tal == tal_2 || spiller_tal == tal_3)
        {
            printf("Du gættede rigtigt\n");
        }
        else
        {
            printf("Du gættede forkert\n");
        }
    } while (spiller_tal != tal_1 && spiller_tal != tal_2 && spiller_tal != tal_3);

    return 0;
}