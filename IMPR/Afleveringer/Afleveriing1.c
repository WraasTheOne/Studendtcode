#include <stdio.h>

int main(void){
    //Først definere jeg min variabel sek. Herefter spørger jeg brugen om hvor mange 
    //sekunder de vil have omregnet
    int sek;
    printf("intast hvor mange sekunder du vil have omregnet \n");
    scanf("%d", &sek); 

    //Nu beregner jeg så hvor mange dage, uger osv det indtastede svarer til
    int sekunder = sek%60;
    int minuter = (sek%3600)/60;
    int timer =(sek%86400)/3600;
    int dage = (sek%604800)/86400;
    int uger = sek/604800;

    //Til slut printer jeg resultatet
    printf("Det er %d uger %d dage %d timer %d minuter %d sekunder \n",uger, dage, timer, minuter, sekunder);
    return 0;
}