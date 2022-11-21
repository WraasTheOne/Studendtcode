#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const char *Yatzy_runder[] = {"1-ere", "2-ere", "3-ere", "4-ere", "5-ere", "6-ere", "Bonus", "Et par", "To par", "Tre ens", "Fire ens", "Lille", "Stor", "Fuld hus", "Chance", "YATZY", "TOTAl"};

#define Yatzyrunder 17

int scandata();

void roll_multiple_dies(int N, int *dies);
void ere(int *dies, int N, int *point);
int print_output(int *point, int *dies, int N, int total);
void bonus(int point[]);
void ens_terninger(int dies[], int ens[], int N, int j);
void par_og_ens(int ens[], int point[], int i);
void special_spil(int ens[], int j, int point[]);
int sum(int point[]);

int main(void)
{
    srand(time(NULL));
    int N = 9, i, j, total;
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

    for (j = 11; j < 16; j++){
        ens_terninger(dies, ens, N, j);
        special_spil(ens, j, point);

    }
    total = sum(point);
    print_output(point, dies, N, total);

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

int print_output(int *point, int *dies, int N, int total)
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
    int sum = 0, j;
    for (j = 0; j < 6; j++)
        {
            sum = sum + (point[j]);
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
                break;
            }
        }
        break;
    case 10:
        for(i = 5; i >=0; i--){
            if(ens[i] > 3){
                point[10] = 4*(i+1);
                break;
            }
        }
        break;
    }
}

void special_spil(int ens[], int j, int point[]){
int i, counter = 0, chance = 0, overskud = 0;
    switch (j)
    {
    case 11:
        if(ens[0] > 0 && ens[1] > 0 && ens[2] > 0 && ens[3] > 0 && ens[4] > 0){
            point[12] = 15;
        }
        break;
    case 12:
        if(ens[1] > 0 && ens[2] > 0 && ens[3] > 0 && ens[4] > 0 && ens[5] > 0){
            point[13] = 20;
        }
        break;
    case 13:
        for(i = 5; i >= 0; i--){
            chance = chance + (ens[i]*(i+1));
            counter += ens[i];
            printf("%d; %d; %d\n", counter, chance, ens[i]);
            if(counter > 5){
                overskud = counter - 5;
                printf("%d;%d; %d; %d\n\n", overskud, counter, chance, ens[i]);
                chance = chance - (overskud*(i+1));
                printf("%d;%d; %d; %d\n", overskud, counter, chance, ens[i]);
                point[14] = chance;
                break;
            }else if (counter == 5)
            {
                printf("%d; %d; %d;\n", counter, chance, ens[i]);
                point[14] = chance;
                break;
            }
        }
    break;
    case 14:
        if(ens[0] > 0 && ens[1] > 0 && ens[2] > 0 && ens[3] > 0 && ens[4] > 0 && ens[5] > 0){
            point[15] = 50;
        }
        break;
    }
}

int sum(int point[]){
    int i, sum = 0;
    for(i = 0; i <= Yatzyrunder; i++){
        sum += point[i];
    }
    return sum;
}
