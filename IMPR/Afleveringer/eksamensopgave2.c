#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const char *Yatzy_runder[] = {"1-ere", "2-ere", "3-ere", "4-ere", "5-ere", "6-ere", "Bonus", "Et par", "To par", "Tre ens", "Fire ens", "Lille", "Stor", "Fuld hus", "Chance", "YATZY", "TOTAl"};

#define Yatzyrunder 16

int scandata();

void roll_multiple_dies(int N, int *dies);
void ere(int *dies, int N, int *point);
int print_output(int *point, int *dies, int N);
void bonus(int point[]);
void ens_terninger(int dies[], int ens[], int N, int j);
void par_og_ens(int ens[], int point[], int i);

int main(void)
{
    srand(time(NULL));
    int N = 9, i, j;
    // N = scandata();
    if (N < 5)
    {
        return -1;
    }

    int *point = malloc(Yatzyrunder * sizeof(int));
    int *dies = malloc(Yatzyrunder * N * sizeof(int));
    int *ens = malloc(6 * sizeof(int));
    roll_multiple_dies(N, dies);
    ere(dies, N, point);
    bonus(point);

    for(j = 7; j < 11; j++){
    ens_terninger(dies, ens, N, j);
    par_og_ens(ens, point, j);
    }
    

    print_output(point, dies, N);

    return 0;
}

void roll_multiple_dies(int N, int *dies)
{
    int i;
    for (i = 0; i < N * Yatzyrunder; i++)
    {
        dies[i] = (rand() % 6) + 1;
    }
}

// int scandata()
// {
//     int N = 0;
//     printf("Yatzy with how many dies (a number less than 5 terminates)");
//     scanf("%d", &N);
//     return N;
// }

void ere(int *dies, int N, int *point)
{
    int j, i;
    int sum = 0;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (dies[i * N + j] == i + 1)
            {
                sum = sum + 1;
            }
        }
        point[i] = sum * (1 + i);
        sum = 0;
    }
}

int print_output(int *point, int *dies, int N)
{
    int j, i;
    for (j = 0; j < Yatzyrunder; j++)
    {
        printf("%s ", Yatzy_runder[j]);
        for (i = 0; i < N; i++)
        {
            printf("%d ", dies[j * N + i]);
        }
        printf("-- %d\n", point[j]);
    }
    return 0;
}

void bonus(int point[])
{
    int sum, i, j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            sum = sum + (point[j]);
        }
    }
    if (sum >= 63)
    {
        point[6] = 50;
    }
}

void ens_terninger(int dies[], int ens[], int N, int j)
{
    int i, k;
    for(k = 0; k < N; k++){
        ens[k] = 0;
    }
    for (i = 0; i < N; i++)
    {
        switch (dies[i + N*j])
        {
        case 1:
            ens[0] += 1;
            break;
        case 2:
            ens[1] += 1;
            break;
        case 3:
            ens[2] += 1;
            break;
        case 4:
            ens[3] += 1;
            break;
        case 5:
            ens[4] += 1;
            break;
        case 6:
            ens[5] += 1;
            break;
        }
    }
}

void par_og_ens(int ens[], int point[], int j){
int i, counter = 0;
    switch (j)
    {
    case 7:
        for(i = 5; i >= 0; i--){
            if(ens[i] >= 2){
                point[7] = 2*(i+1);
                break;
            }
        }
        break;
    case 8:
        for(i = 5; i >= 0; i--){
            if(ens[i] >= 2){
                point[8] += (2*(i+1));
                counter += 1;
            }
            if(counter == 2){
                break;
            }
        }
        break;
    case 9:
        for(i = 5; i >=0; i--){
            if(ens[i] > 2){
                point[9] = 3*(i+1);
                printf("%d; %d; %d; %d\n", point[9], i, j, ens[i]);
                break;
            }
        }
        break;
    case 10:
        for(i = 5; i >=0; i--){
            if(ens[i] > 3){
                point[10] = 4*(i+1);
                printf("%d; %d; %d; %d\n", point[10], i, j, ens[i]);
                break;
            }
        }
        break;
    }
}




