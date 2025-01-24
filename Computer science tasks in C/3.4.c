#include<stdio.h>
#include<math.h>
/* №3.4 Определить квадратный корень от вещественного числа*/
int main(){
    double yn, y0, r, kor2, prow;
    int n;
    printf("r = "); scanf("%lf", &r);
    printf("n = "); scanf("%d", &n);
    if (r > 0){y0 = r;}
        kor2 = sqrt(r);
    for (int i = 0; i <= n; i++){
        yn = y0;
        prow = yn * yn;
        printf("%4d, %20.18lf, %20.18lf, %20.18lf \n", i, yn, kor2, prow);
        y0 = (yn + (r / yn)) / 2;}
 return 0;
 }