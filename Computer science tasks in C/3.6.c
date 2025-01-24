#include <stdio.h>
//№3.6 Дано к от 2 до 20. Найти коэффициенты к-го многочлена Чебышева по формуле: T0(x)=1, T1(x)=x Tn(x)=2xTn-1(x)-Tn-2(x)
void chebyshevPolynomial(int k) {
    int T0 = 1, T1 = 2, Tn, Tnm1 = 1, Tnm2 = 0;
    for (int n = 2; n <= k; n++) {
        Tn = 2 * T1 * Tnm1 - Tnm2;
        Tnm2 = Tnm1;
        Tnm1 = T1;
        T1 = Tn;}
    printf("T%d(x) = %d\n", k, Tn);}

int main() {
    int k;
    printf("Введите к от 2 до 20: "); scanf("%d", &k);
    if (k >= 2 && k <= 20) {
        chebyshevPolynomial(k);}
    return 0;
}