#include <stdio.h>

void udskift(char s[], char c1, char c2);

int main(void){
    char str[] = "foodback";

    printf("%s\n", str);

    udskift(str, 'o','e');

    printf("%s\n",str);

    return 0;
}

void udskift(char s[], char c1, char c2){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == c1){
            s[i] = c2;
        }
        i++;
    }
}