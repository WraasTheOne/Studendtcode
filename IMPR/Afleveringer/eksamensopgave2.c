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
    roll_multiple_dies(N, dies);
    ere(dies, N, point);

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
                printf("%d\n", sum);
            }
        }
        point[i] = sum;
        sum = 0;
    }
}

int print_output(int *point, int *dies, int N)
{
    int j, i;
    for (j = 0; j < Yatzyrunder; j++)
    {
        printf("%s ", *Yatzy_runder);
        for (i = 0; i < N; i++)
        {
            printf("%d ", dies[j * N + i]);
        }
        printf("-- %d\n", point[j]);
    }
    return 0;
}