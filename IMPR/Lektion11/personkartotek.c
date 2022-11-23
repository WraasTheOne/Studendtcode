#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONS 
#define MAX_NAME_LGT 50

 typedef struct person{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
  } person;

person *indlæs_i_array(FILE *file);

int recorded = 0;

int main(void){
    person *array;
    FILE *file = fopen("fil.txt", "r");

    array = indlæs_i_array(file);

    printf("%s\n", array[0].fornavn);

    return 0;
}

person *indlæs_i_array(FILE *file){
    char c;
    int i;
    while (!feof(file))
    {
        fscanf(file, "%c", &c);
        if(c == '\n'){
            recorded ++;
        }
    }

    person *p = malloc(recorded*sizeof(person));

    rewind(file);
    for (i = 0; i < recorded; i++)
    {
        fscanf(file,"%s %s, %s %d, %d %s\n", p[i].fornavn, p[i].efternavn, p[i].vejnavn,&p[i].vejnummer, &p[i].postnummer, p[i].bynavn);
    }
    

    return p;
}