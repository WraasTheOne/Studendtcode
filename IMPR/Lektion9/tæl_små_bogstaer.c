#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lille_bogstav_detect(char s[]);


int main(void){
    char str[] = "heeeee";
    int counter = 0;

    counter = lille_bogstav_detect(str);

    printf("%d\n", counter);


    return 0;
}

int lille_bogstav_detect(char s[]){
    int i = 0, counter = 0;

    while(s[i] != '\0'){
        if(islower(s[i]) > 0){
            counter += 1;
        }
    i++;
    }
    return counter;

}


void firstlower(char s[]){


}