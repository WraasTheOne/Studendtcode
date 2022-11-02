#include <stdio.h>

#define LENGHT 10

int main(void)
{

    double priser[LENGHT];
    int i;
    double samlet_pris = 0;

    printf("indtast priserne på de ønskede varer\n");

    for (i = 0; i < LENGHT; i++)
    {
        scanf("%lf", &priser[i]);
    }

    printf("dermed har du følgende priser for dit produkt\n");

   for (i = 0; i < LENGHT; i++)
    {
        printf("%lf\n", priser[i]);
        samlet_pris += priser[i];
    }

    printf("din samlede pris er %lf\n",samlet_pris);

    return 0;
}