#include <stdio.h>
#include <math.h>
// №3.1.3 Многочлены Тейлора. Экспонента
int main(){
    double s=0, s1=1, x, ex;
    int n;
    printf("x = "); scanf("%lf", &x);
    printf("n = "); scanf("%d", &n);
    ex=exp(x);
    for (int i=1; i<=n; i++){
        s+=s1;
        printf("%4d, %20.18lf, %20.18lf \n", i, s, ex);
        s1=s1*x/i;}
    return 0;
}