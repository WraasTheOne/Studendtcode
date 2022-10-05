#include <stdio.h>
#include <math.h>

void scale(int g_bredde, int g_laengde, int *n_bredde, int *n_laengde, int faktor);

int main(void){
    int g_bredde = 3, g_laengde = 5, n_bredde, n_laengde, faktor = 2;

    scale(g_bredde, g_laengde, &n_bredde, &n_laengde, faktor);

    return 0;
}


void scale(int g_bredde, int g_laengde, int *n_bredde, int *n_laengde, int faktor){
    *n_bredde = g_bredde * faktor;
    *n_laengde = g_laengde * faktor;

}