
#include <stdio.h>
#include <math.h>

void decToBinary(float num) {
    int Binary[32];
    int Integral = num;
    float fractional = num - Integral;
    int i = 0;
    while (Integral) {
        Binary[i] = Integral % 2;
        Integral /= 2;
        i++;
    }
    printf("5.26.a) bin: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", Binary[j]);
    printf(".");
    i = 0;
    while (i < 8) {
        fractional *= 2;
        int fract_bit = fractional;
        if (fract_bit == 1) {
            fractional -= fract_bit;
            printf("1");
        }
        else
            printf("0");
        i++;
    }
    printf("\n");
}

void decToHexa(float num) {
    int Integral = num;
    float fractional = num - Integral;
    char hexaDeciNum[100];
    int i = 0;
    while (Integral != 0) {
        int temp = 0;
        temp = Integral % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        Integral = Integral / 16;
    }
    printf("5.26.b) hex: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexaDeciNum[j]);
    printf(".");
    i = 0;
    while (i < 8) {
        fractional *= 16;
        int fract_bit = fractional;
        if (fract_bit != 0) {
            fractional -= fract_bit;
            printf("%c", (fract_bit < 10) ? (48 + fract_bit) : (55 + fract_bit));
        }
        else
            printf("0");
        i++;
    }
    printf("\n");
}

void decToOctal(float num) {
    int Integral = num;
    float fractional = num - Integral;
    int octalNum[100];
    int i = 0;
    while (Integral != 0) {
        octalNum[i] = Integral % 8;
        Integral = Integral / 8;
        i++;
    }
    printf("5.26.c) oct: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", octalNum[j]);
    printf(".");
    i = 0;
    while (i < 8) {
        fractional *= 8;
        int fract_bit = fractional;
        if (fract_bit != 0) {
            fractional -= fract_bit;
            printf("%d", fract_bit);
        }
        else
            printf("0");
        i++;
    }
    printf("\n");
}

void decToBaseN(float num, int base) {
    int Integral = num;
    float fractional = num - Integral;
    char baseNum[100];
    int i = 0;
    while (Integral != 0) {
        int temp = 0;
        temp = Integral % base;
        if (temp < 10) {
            baseNum[i] = temp + 48;
            i++;
        }
        else {
            baseNum[i] = temp + 55;
            i++;
        }
        Integral = Integral / base;
    }
    printf("5.26.с) N/A sis: ", base);
    for (int j = i - 1; j >= 0; j--)
        printf("%c", baseNum[j]);
    printf(".");
    i = 0;
    while (i < 8) {
        fractional *= base;
        int fract_bit = fractional;
        if (fract_bit != 0) {
            fractional -= fract_bit;
            printf("%c", (fract_bit < 10) ? (48 + fract_bit) : (55 + fract_bit));
        }
        else
            printf("0");
        i++;
    }
    printf("\n");
}

int main() {
    float num;
    int sis;
    printf("Num: "); scanf_s("%f", &num);
    printf("sis: "); scanf_s("%d", &sis);
    decToBinary(num); decToHexa(num); decToOctal(num); decToBaseN(num, sis);
    return 0;
}