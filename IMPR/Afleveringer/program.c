/*
Nicholas Mazur Hansen
nmha22@student.aau.dk
Cyber- og computerteknologi
*/



// præprocesser 
// libary inclusions
#include <stdio.h>
#include <math.h>

//prototyper
int run_calculator();
int is_binary(char operator);
void scan_data(char *operator, double * operand);
double do_next_op(char operator, double operand, double akkumulator);

int main(void)
{

    run_calculator();
    return 0;
}

// run_calulator står for at køre de nødvendige funktioner
int run_calculator()
{
    char operator;
    double operand, akkumulator = 0;

    do
    {
        scan_data(&operator, & operand);
        if (operator!= 'q')
        {
            akkumulator = do_next_op(operator, operand, akkumulator);
            printf("Result so far is %lf\n", akkumulator);
        }
        else
        {
            printf("Final result is %lf\n", akkumulator);
        }

    } while (operator!= 'q');

    return akkumulator;
}

// scan_data har til formål at indhente de indput som brugeren taster ind
void scan_data(char *operator, double * operand)
{
    printf("Enter operator, and and an optional operand:");
    scanf(" %c", operator);
    if (is_binary(*operator) == 1)
    {
        scanf("%lf", operand);
    }
}

// do_next_op er en funktion som udfører den påkrvende matematiske operation
double do_next_op(char operator, double operand, double akkumulator)
{
    switch (operator)
    {
    case '+':
        akkumulator += operand;
        break;
    case '-':
        akkumulator -= operand;
        break;
    case '*':
        akkumulator *= operand;
        break;
    case '/':
        if (operand == 0)
        {
            akkumulator = akkumulator;
        }
        else
        {
            akkumulator /= operand;
        }
        break;
    case '^':
        akkumulator = pow(akkumulator, operand);
        break;
    case '#':
        if (akkumulator <= 0)
        {
            akkumulator = akkumulator;
        }
        else
        {
            akkumulator = sqrt(akkumulator);
        }
        break;
    case '%':
        akkumulator = -akkumulator;
        break;
    case '!':
        akkumulator = (1 / (akkumulator));
        break;
    default:
        break;
    }
    return akkumulator;
}

// is_binary skal afgøre om brugeren har tastet en binær eller unær operator ind
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



