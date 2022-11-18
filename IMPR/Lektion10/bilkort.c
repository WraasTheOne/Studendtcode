#include <stdio.h>
#include <string.h>

typedef struct bilkort
{
    char navn[20];
    int kmt;
    int hk;
    int acc;
    int ccm; 
} bilkort;

void print_bilkort(bilkort b);
bilkort hurtigste(bilkort a, bilkort b);
bilkort indlæs_bil();


int main(void){

    bilkort bil1 = {"Lotus", 200, 110, 8, 1973};
    bilkort bil2 = {"Mercedes", 215, 160, 9, 5520};

    print_bilkort(bil1);
    printf("\n");
    print_bilkort(bil2);

    bilkort bil_hurtig = hurtigste(bil1,bil2);

    printf("\n");
    print_bilkort(bil_hurtig);

    bilkort min_bil = indlæs_bil();
    print_bilkort(min_bil);

    return 0;
}

void print_bilkort(bilkort b){
    char navnet[20];
    strcpy(navnet,b.navn);
    int hastighed = b.kmt;
    int hk = b.hk;
    int acc = b.acc;
    int ccm = b.ccm;

    printf("Navn: %s\n", navnet);
    printf("Hastighed: %d\n", hastighed);
    printf("HK: %d\n", hk);
    printf("acceleration: %d\n", acc);
    printf("ccm: %d\n", ccm);

}

bilkort hurtigste(bilkort a, bilkort b){
    if(a.kmt > b.kmt){
        return a;
    }else{
        return b;
    }

}

bilkort indlæs_bil(){
    bilkort min;
    char navnet[20];
    int hastighed, HK,acc, ccm;
    printf("Navn: ");
    scanf("%s", navnet);
    printf("hastighed: ");
    scanf("%d", &hastighed);
    printf("HK: ");
    scanf("%d", &HK);
    printf("acc: ");
    scanf("%d", &acc);
    printf("ccm: ");
    scanf("%d", &ccm);

    strcpy(min.navn, navnet);
    min.kmt = hastighed;
    min.hk = HK;
    min.acc = acc;
    min.ccm = ccm;

}