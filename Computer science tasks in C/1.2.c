#include <stdio.h>
/* №1.2 Нахождение суммы и произведения чисел по формулам */
int main() {
    int N;
    printf("Number = "); scanf("%d", &N);

    // 1) y = S i; y = П i
    int s1 = 0, p1 = 1;
    for (int i = 1; i <= N; i++) {
        s1 += i;
        p1 *= i;}
    printf("1. Сумма = %d\n", s1); printf("   Произведение = %d\n", p1);

    // 2) y = S (1/i); y = П (1/i)
    float s2 = 0, p2 = 1;
    for (int i = 1; i <= N; i++) {
        s2 += 1.0 / i;
        p2 *= 1.0 / i;}
    printf("2. Сумма = %.5f\n", s2); printf("   Произведение = %.5f\n", p2);

    // 3) y = S (i/(i+1)); y = П (i/(i+1))
    float s3 = 0, p3 = 1;
    for (int i = 1; i <= N; i++) {
        s3 += (float) i / (i + 1);
        p3 *= (float) i / (i + 1);}
    printf("3. Сумма =  %.5f\n", s3); printf("   Произведение = %.5f\n", p3);

    // 4) y = S S i j; y = П П 1/(i+j)
    int s4 = 0;
    float p4 = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            s4 += i + j;
            p4 *= 1.0 / (i + j);}}
    printf("4. Сумма =  %d\n", s4); printf("   Произведение = %.5f\n", p4);

    // 5) y = S П i j; y = П S i j
    int s5 = 0, p5 = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            s5 += i * j;
            p5 *= i + j;}}
    printf("5. Сумма = %d\n", s5); printf("   Произведение = %d\n", p5);
    return 0;
}
