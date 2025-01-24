#include <stdio.h>

void decToBin(int decimalNumber) {
    int binNum[32];
    int i = 0;

    while (decimalNumber > 0) {
        binNum[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }

    printf("in bin: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binNum[j]);
    }
}

int main() {
    int decimalNumber = 327;
    decToBin(decimalNumber);

    return 0;
}
