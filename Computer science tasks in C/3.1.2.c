#include <stdio.h>
#include <math.h>
// №3.1.2 Многочлены Тейлора. Синус
int main(){
    double s, s1, x, sinx;
    int n;
    printf("x = "); scanf("%lf", &x);
    printf("n = "); scanf("%d", &n);
    sinx=sin(x);
    s1=-x;
    for (int i=1; i<=n; i+=2){
        s=s-s1;
        printf("%4d, %20.18lf, %20.18lf \n", i, s, sinx);
        s1=-(s1*x*x)/((i+1)*(i+2));}
    return 0;
}