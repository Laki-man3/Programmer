#include <stdio.h>
#include <math.h>
// №3.1.4 Многочлены Тейлора. ln(1+x)
int main(){
    double s, s1, x, lx;
    int n;
    printf("x = "); scanf("%lf", &x);
    printf("n = "); scanf("%d", &n);
    lx=log(x+1);
    s1=x;
    if(fabs(x)==1){
        for (int i=1; i<=n; i++){
            s+=(s1/i);
            printf("%4d, %20.18lf, %20.18lf \n", i, s, lx);
            s1=-s1*x;}}
    return 0;
}