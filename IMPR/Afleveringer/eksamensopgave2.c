#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const char *Yatzy_runder[] = {"1-ere", "2-ere", "3-ere", "4-ere", "5-ere", "6-ere", "Bonus", "Et par", "To par", "Tre ens", "Fire ens", "Lille", "Stor", "Fuld hus", "Chance", "YATZY", "TOTAl"};

#define Yatzyrunder 16

int scandata();
void roll_multiple_dies(int N, int dies[]);
void ere(int dies[], int N, int point[], int i);
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
    int dies[N][Yatzyrunder];

    roll_multiple_dies(N, dies);

    /*for (i = 1; i < 7; i++)
    {
        roll_multiple_dies(N, dies);

        ere(dies, N, point, i);
        print_output(point, dies);
    }
    roll_multiple_dies(N, dies);

    ere(dies, N, point);

    print_output(point, dies);*/

    return 0;
}

void roll_multiple_dies(int N, int dies[])
{
    int i;
    
        for (i = 0; i < N; i++)
        {
            dies[i] = (rand() % 6) + 1;
        }
    
}

int scandata()
{
    int N = 0;
    printf("Yatzy with how many dies (a number less than 5 terminates)");
    scanf("%d", &N);
    return N;
}

void ere(int dies[], int N, int point[], int i)
{
    int j = 0;
    int sum = 0;
    for (j = 0; j < N; j++)
    {
        if (dies[j] == i)
        {
            sum = sum + 1;
        }
    }
    point[i - 1] = sum;
    printf("%d\n", sum);
    sum = 0;
}

int print_output(int point[], int dies[])
{
    int i, j;
    for (i = 0; i < Yatzyrunder; i++)
    {
        printf("%s", Yatzy_runder[i]);
        for (j = 0; j < 9; j++)
    {
        printf("%d ", dies[j]);
    }
        printf(" -- %d\n", point[i]);
    }
    printf("\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d ", dies[i]);
    }

    printf("\n");

    return 0;
}