#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "primes.h"

int primtalresultat (int bob);
int is_prime(int i);

int main(void) {
    int prim1,prim2,i=1,j,isPrime,primeNumber = 1;
    int fejl = 1;
    printf("Indtast to heltal større end 6\n");
    scanf("%d %d",&prim1,&prim2);


    for (i = prim1;i<=prim2;i++) {
        if (i % 2 != 0) {
            continue;
        }
        if (primtalresultat(i)) {
            printf("i er %d succes\n",i);
        }
        else {
            printf("i er %d fail\n",i);
        }
            }

    return 0;
}
int primtalresultat (int bob) {
    int i;
    for (i=1;i<=bob;i++) {
        if (is_prime(bob-i) && is_prime(i)) {
            printf("de to primtal er %d og %d\n",bob-i,i);
            return 1;
        }
    }
    return 0;
}