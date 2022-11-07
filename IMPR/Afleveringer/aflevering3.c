#include <stdio.h>
#include <math.h>

void Trap(double a, double b, double (*f)(double), int n);
double g(double x);
double h(double x);

int main(void)
{
    double a = 10, b = 80;
    double (*f)(double);
    char funktions_valg;
    int n;

    printf("angiv værdier for a,b og n, med mellemrum mellem dem\n");
    scanf("%lf %lf %d",&a,&b,&n);

    printf("vil du bruge funktionen h eller g\n");
    scanf(" %c",&funktions_valg);

    switch (funktions_valg)
    {
    case 'h':
        f = h;
        break;
    case 'g':
        f = g;
    default:
        printf("error");
        break;
    }

    Trap(a, b, (*f),n);

    return 0;
}

void Trap(double a, double b, double (*f)(double), int n)
{
    double h_bergnet, sum = 0, x, T = 0;
    int i;
    h_bergnet = (b - a) / n;
    for (i = 1; i < n; i++)
    {
        x = a + (i * h_bergnet);
        sum = sum + (*f)(x);
    }


    T = (h_bergnet/2)*((*f)(a)+(*f)(b)+2*(sum));

    printf("%lf",T);
}

double h(double x)
{
    return sqrt((4 - pow(x, 2)));
}

double g(double x)
{
    return (pow(x, 2)) * sin(x);
}
