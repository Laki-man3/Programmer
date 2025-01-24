#include <stdio.h>
#include <math.h>

/* №1.6 (2 вариант) Нахождение коэффициентов квадратного уравнения через корни, 
а затем повторное нахождение корней через них.*/

int main(){
  double x1, x2, a, b, c, d;
  printf("x1 = "); scanf("%lf", &x1);
  printf("x2 = "); scanf("%lf", &x2);
  c = x1*x2;
  b = -(x1+x2);
  a=1.0;
  d=b*b-(4*a*c);
  x1=(-b-sqrt(d))/(2*a);
  x2=(-b+sqrt(d))/(2*a);
  if (d<0){ printf("Нет корней"); return 0;}
  if (x1>x2){x2=c/(x1);}
     else    {x1=x2; x2=c/(x1);}
  printf("x1 = %20.18lf x2 = %20.18lf", x1, x2);
} 
