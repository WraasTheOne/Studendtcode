#include <stdio.h>
#include <math.h>

void get_input(char *do_next_op, double *operand);

int main(void)
{

    char do_next_op;
    double operand;
    get_input(&do_next_op, &operand);

    

    return 0;
}


void get_input(char *do_next_op, double *operand){
    printf("indtast en operator, og en operand");
    scanf("%c %d\n", do_next_op, operand);
}