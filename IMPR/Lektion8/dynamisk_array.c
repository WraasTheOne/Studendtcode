#include <stdio.h>
#include <stdlib.h> 

int sammenligning(const void *p1, const void *p2);
double *generer_array(int length);

int main(void){
  int i,n;
  double pris;
  double samlet_pris = 0;
  int length;
  double *priser;

  printf("indtast hvor mange varer du har og hvad prisen på dem alle skal være (adskilt af komme)\n");
  scanf("%d,%d", &length, &n);

  priser = generer_array(length);

  for(i = 0; i < length; i++){
    priser[i] = n;
  }

  for(i = 0; i < length; i++){
    printf("%lf\n",priser[i]);

  }

}

double *generer_array(int length){
  double *priser = (double *) malloc(length * sizeof(double));
  int i;
  
  if(priser == NULL){
    printf("Fejl: Hukkommelse kunne ikke allokeres\n");
    exit(EXIT_FAILURE);
  }

  /*for(i = 0; i < length; i++){
    printf("Giv mig en pris:\n");
    scanf("%lf", &priser[i]);
  }*/

  return priser;
}

int sammenligning(const void *p1, const void *p2){
  double *dp1 = (double *) p1;
  double *dp2 = (double *) p2;

  double d1 = *dp1;
  double d2 = *dp2;

  if(d1 < d2){
    //d1 er billigst
    //(det vil sige d1 skal før d2 i sorteringen)
    return -1;
  } else if (d2 < d1){
    //d2 er billigst
    //(det vil sige d2 skal før d1 i sorteringen)
    return 1;
  } else {
    return 0;
  }
}
