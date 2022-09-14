#include <stdio.h>

int main(void){
    int sek;
    printf("intast hvor mange sekunder du vil have omregnet \n");
    scanf("%d", &sek); 

    int sekunder = sek%60;
    int minuter = (sek%3600)/60;
    int timer =(sek%86400)/3600;
    int dage = (sek%604800)/86400;
    int uger = sek/604800;

    printf("Det er %d uger %d dage %d timer %d minuter %d sekunder \n",uger, dage, timer, minuter, sekunder);
    return 0;
}