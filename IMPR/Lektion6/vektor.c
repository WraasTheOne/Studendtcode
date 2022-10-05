#include <stdio.h>
#include <math.h>

void vektor_plus(int u1, int u2, int v1, int v2, int *w1, int *w2);
void vektor_minus(int u1, int u2, int v1, int v2, int *w1, int *w2);
void vektor_prik(int u1, int u2, int v1, int v2, int *w1, int *w2, int *prikprodukt);
void vektor_leangde(int u1, int u2, int v1, int v2, int *w1, int *w2, int *leangde);

int main(void)
{
    int u1 = 2, u2 = 1, v1 = 5, v2 = 8, w1, w2, prikprodukt, leangde;

    vektor_plus(u1, u2, v1, v2, &w1, &w2);

    printf("din samlede vektor hedder: (%d,%d)\n", w1, w2);

    vektor_minus(u1, u2, v1, v2, &w1, &w2);

    printf("du har trukket dem fra hinanden: (%d,%d)\n", w1, w2);

    vektor_prik(u1, u2, v1, v2, &w1, &w2, &prikprodukt);

    printf("du prikker dem: %d\n", prikprodukt);

    vektor_leangde(u1, u2, v1, v2, &w1, &w2, &leangde);

    printf("længden er: %d\n", leangde);

    return 0;
}

void vektor_plus(int u1, int u2, int v1, int v2, int *w1, int *w2)
{
    *w1 = u1 + v1;
    *w2 = u2 + v2;
}

void vektor_minus(int u1, int u2, int v1, int v2, int *w1, int *w2)
{
    *w1 = u1 - v1;
    *w2 = u2 - v2;
}

void vektor_prik(int u1, int u2, int v1, int v2, int *w1, int *w2, int *prikprodukt)
{
    *w1 = u1 * v1;
    *w2 = u2 * v2;
    *prikprodukt = *w1 + *w2;
}

void vektor_leangde(int u1, int u2, int v1, int v2, int *w1, int *w2, int *leangde)
{
    *w1 = u1 * v1;
    *w2 = u2 * v2;
    *leangde = sqrt(pow(u1 + v1, 2) + pow(u2, v2));
}
