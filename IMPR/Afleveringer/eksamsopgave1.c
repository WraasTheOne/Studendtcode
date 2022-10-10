#include <stdio.h>
#include <math.h>

int run_calculator();
int is_binary(char operator);
void scan_data(char *operator, double * operand);
void do_next_op(char operator, double operand, double *akkumulator);

int main(void)
{

    run_calculator();
    return 0;
}

int run_calculator()
{
    char operator;
    double operand, akkumulator = 0;

    do
    {
        scan_data(&operator, & operand);
        do_next_op(operator, operand, &akkumulator);
        if (operator!= 'q')
        {
            printf("nu er din sum %lf\n", akkumulator);
        }
        else
        {
            printf("din sum er dermed %lf\n", akkumulator);
        }
    } while (operator!= 'q');

    return 0;
}

void scan_data(char *operator, double * operand)
{
    scanf("%c", operator);
    if (is_binary(*operator) == 1)
    {
        scanf("%lf", operand);
    }
}

void do_next_op(char operator, double operand, double *akkumulator)
{
    switch (operator)
    {
    case '+':
        *akkumulator += operand;
        break;
    case '-':
        *akkumulator -= operand;
        break;
    case '*':
        *akkumulator *= operand;
        break;
    case '/':
        *akkumulator /= operand;
        break;
    case '^':
        *akkumulator = pow(*akkumulator, operand);
        break;
    case '#':
        *akkumulator = sqrt(*akkumulator);
        break;
    case '%':
        *akkumulator = -*akkumulator;
        break;
    case '!':
        *akkumulator = (1 / (*akkumulator));
        break;
    default:
        break;
    }
}

int is_binary(char operator)
{
    if (operator== '#' || operator== '%' || operator== '!' || operator== 'q')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}