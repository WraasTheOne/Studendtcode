#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* udskift2(char s[],char c1, char c2 );
char* udskift3(char s[]);

int main(void){
    char str[] = "Foodback";
    char *str2;
    char *str3;

    printf("streng: %s\n", str);

    str2 = udskift2(str, 'o', 'e');
    str3 = udskift3(str);

    printf("streng 1: %s\nStreng 2: %s\nStreng 3: %s\n", str, str2,str3);

    free(str2);

    return 0;
}

char* udskift2(char s[],char c1, char c2 ){
    int i = 0;

    char *s2 = (char*) malloc((strlen(s) + 1)* sizeof(char));

    /*if(s2 == NULL){
        exit(EXIT_FAILURE);
    }*/


    while(s[i] != '\0'){
        if(s[i] == c1){
            s2[i] = c2;
        }else{
             s2[i] = s[i];
        }
        i++;
    }
    s2[i] = '!';
    i++;
    s2[i] = '\0';


    return s2;
}

char* udskift3(char s[]){
    int i = 0, j = 0;

    char *s3 = (char*) malloc((2*strlen(s) + 1)* sizeof(char));

    /*if(s2 == NULL){
        exit(EXIT_FAILURE);
    }*/


    while(s[i] != '\0'){
        s3[i] = s[j];
        i++;
        s3[i] = s[j];
        j++;
        i++;
    }
    s3[i] = '!';
    i++;
    s3[i] = '\0';


    return s3;
}