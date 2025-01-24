#include <stdio.h>
#include <math.h>
// №3.1.3 Многочлены Тейлора. Косинус
int main(){
    double s=0, s1=-1, x, cosx;
    int n;
    printf("x = "); scanf("%lf", &x);
    printf("n = "); scanf("%d", &n);
    cosx=cos(x);
    for (int i=0; i<=n; i+=2){
        s=s-s1;
        printf("%4d, %20.18lf, %20.18lf \n", i, s, cosx);
        s1=-(s1*x*x)/((i+1)*(i+2));}
    return 0;
}