#include <stdio.h>
#include <math.h>

int run_calculator();
int is_binary(char operator);
void scan_data(char *operator, double *operand);
double do_next_op(char operator, double operand, double akkumulator);

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
        scan_data(&operator, &operand);
        if(operator != 'q'){
            akkumulator = do_next_op(operator, operand, akkumulator);
            printf("Result so far is %lf\n", akkumulator);
        }else{
            printf("Final result is %lf\n", akkumulator);
        }

    } while (operator!= 'q');

    return akkumulator;
}

void scan_data(char *operator, double *operand)
{
    scanf("%c", operator);
    if (is_binary(*operator) == 1)
    {
        scanf("%lf", operand);
    }
}

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
        if(operand == 0){
            akkumulator = akkumulator;
        }else 
        {
            akkumulator /= operand;
        }
        break;
    case '^':
        akkumulator = pow(akkumulator, operand);
        break;
    case '#':
        if(akkumulator <= 0){
            akkumulator = akkumulator;       
        }else{
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