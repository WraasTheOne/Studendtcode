#include <stdio.h>

double Execute(int n, double s, char funktion);

int main(void)
{
    int n;
    double s, output;
    char funktion;

    printf("indtast hvilken funktion du vil have, hvor mange gange den skal gentages og startværdien, adskildt af komma\n");
    scanf("%c, %d, %lf", &funktion, &n, &s);

    s = Execute(n, s, funktion);

    printf("%lf\n", s);

    return 0;
}

double Execute(int n, double s, char funktion)
{
    int i;

    switch (funktion)
    {
    case 'h':
        for (i = 0; i <= n; i++)
        {
            s = (s / 2);
        }
        return s;

    default:
        printf("error");
        break;
    }
}
