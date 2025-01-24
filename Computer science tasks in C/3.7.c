#include <stdio.h>
#include <stdlib.h>
/*№3.7 Нахождение наибольшего общего делителя двух чисел N и M по рекуррентному соотношению. 
Nk = Nk-2 - INT(Nk-2 / Nk-1) N k-1 k=2,3 ...
N0 = max(|N|, |M|) N1 = min(|N|, |M|)
Если Nk = 0 => НОД = Nk-1*/

int gcd(int N, int M) {
    N = abs(N);
    M = abs(M);
    int N0 = (N > M) ? N : M; //если N>M, то N0=N, иначе N0=M.
    int N1 = (N < M) ? N : M; //если N<M, то N1=N, иначе N1=M.
    int Nk_2 = N0;
    int Nk_1 = N1;
    int Nk = 0;
    while (Nk_1 != 0) {
        Nk = Nk_2 - (Nk_2 / Nk_1) * Nk_1;
        Nk_2 = Nk_1;
        Nk_1 = Nk;}
    return Nk_2;}

int main() {
    int N, M;
    printf("Введите n и m:\n"); scanf("%d %d", &N, &M);
    int result = gcd(N, M);
    printf("Наибольший общий делитель %d и %d: %d\n", N, M, result);
    return 0;}