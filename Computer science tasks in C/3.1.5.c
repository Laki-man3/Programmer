#include <stdio.h>
#include <math.h>
// №3.1.4 Многочлены Тейлора. arctg(x)
int main(){
    double s, s1, x, atgx;
    int n;
    printf("x = "); scanf("%lf", &x);
    printf("n = "); scanf("%d", &n);
    atgx=atan(x);
    s1=x;
    if(fabs(x)==1){
        for (int i=1; i<=n; i+=2){
            s+=(s1/i);
            printf("%4d, %20.18lf, %20.18lf \n", i, s, atgx);
            s1=-s1*x*x;}}
    return 0;
}