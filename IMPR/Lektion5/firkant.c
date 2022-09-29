#include <stdio.h>
#include <math.h>

double regn_samlet_side_laengde(double p1_x, double p1_y, double p2_x, double p2_y, 
                                double p3_x, double p3_y, double p4_x, double p4_y);

double regn_side(double pA_x, double pA_y, double pB_x, double pB_y);

void print_samlet_side_laengde(double samlet);

int main(void){
  double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y, samlet;
  
  printf("Giv mig tre koordinatpar. Alt adskilles med mellemrum:\n");
  scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y, &p4_x, &p4_y);

  samlet = regn_samlet_side_laengde(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y);
 
  print_samlet_side_laengde(samlet);

  return 0;
}

double regn_samlet_side_laengde(double p1_x, double p1_y, double p2_x, double p2_y, 
                                double p3_x, double p3_y, double p4_x, double p4_y){
  double side14 = regn_side(p1_x,p1_y,p4_x,p4_y);
  double side13 = regn_side(p1_x,p1_y,p3_x,p3_y);
  double side23 = regn_side(p2_x,p2_y,p3_x,p3_y);
  double side24 = regn_side(p2_x,p2_y,p4_x,p4_y);

  return side14 + side13 + side23 + side24;
}

double regn_side(double pA_x, double pA_y, double pB_x, double pB_y){
  double delta_x = pA_x - pB_x;
  double delta_y = pA_y - pB_y;
  return sqrt(delta_x*delta_x + delta_y*delta_y);
}

void print_samlet_side_laengde(double samlet){
  printf("Kaere bruger. Jeg nu regnet den samlede sidelaengde. Det viste sig at den var %lf.\n", samlet);
}


