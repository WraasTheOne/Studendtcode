#include <stdio.h>  

int main(void){
  float x,y,z;
  printf("Give me three: ");
  scanf("%f%f%f",&x,&y,&z);
  printf("The result: %f\n",(x+y+z) / 3.0);  
  return 0;
}