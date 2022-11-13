#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define Yatzyrunder 16

int scandata();
void roll_multiple_dies(int N, int dies[]);

int main(void)
{
    int N = 0;
    N = scandata();
    if (N < 5)
    {
        return -1;
    }
    int point[Yatzyrunder];
    int dies[N];
    roll_multiple_dies(N, dies);

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
        //hej
    }
}