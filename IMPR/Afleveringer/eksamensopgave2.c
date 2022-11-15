#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const char *Yatzy_runder[] = {"1-ere", "2-ere", "3-ere", "4-ere", "5-ere", "6-ere", "Et par", "To par", "Tre ens", "Fire ens", "Lille", "Stor", "Fuld hus", "Chance", "YATZY", "TOTAl"};

#define Yatzyrunder 16

int scandata();
void roll_multiple_dies(int N, int dies[]);
void ere(int dies[], int N, int point[]);
int print_output(int point[], int dies[]);

int main(void)
{
    srand(time(NULL));
    int N = 9, i;
    // N = scandata();
    if (N < 5)
    {
        return -1;
    }

    int point[Yatzyrunder];
    int dies[N];
    roll_multiple_dies(N, dies);

    ere(dies, N, point);

    print_output(point, dies);

    return 0;
}

int scandata()
{
    int N = 0;
    printf("Yatzy with how many dies (a number less than 5 terminates)");
    scanf("%d", &N);
    return N;
}

void roll_multiple_dies(int N, int dies[])
{

    int i;
    for (i = 0; i < N; i++)
    {
        dies[i] = (rand() % 6) + 1;
    }
}

void ere(int dies[], int N, int point[])
{
    int i, j;
    int sum = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (dies[j] == i)
            {
                sum = sum +1;
            }
            
        }
        point[i] = sum;
        sum = 0;
    }
}

int print_output(int point[], int dies[])
{
    int i;
    for (i = 0; i < Yatzyrunder; i++)
    {
        printf("%s; %d \n", Yatzy_runder[i], point[i]);
    }
    printf("\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d ", dies[i]);
    }

    printf("\n");

    return 0;
}