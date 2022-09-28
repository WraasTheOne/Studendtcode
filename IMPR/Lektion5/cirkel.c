#include <stdio.h>

#define PI 3.14159

double regn_omkreds(double radius);
void print_omkreds(double omkre);

int main(void){
  double radius, omkreds, omkreds2;

  //Læse tal ind
  printf("Indtast en radius:\n");
  scanf("%lf", &radius);

  //Regne omkredsen
  omkreds = regn_omkreds(radius);

  omkreds2 = regn_omkreds(2 * radius);

  

  //Printe ud
  print_omkreds(omkreds);
  print_omkreds(omkreds2);

  return 0;
}

double regn_omkreds(double radius){
  return 2 * PI * radius;
}

void print_omkreds(double omkre){
  printf("Omkredsen er %lf\n", omkre);
}


