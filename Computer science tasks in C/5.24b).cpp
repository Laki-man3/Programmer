#include <stdio.h>

void decToHex(int decimalNumber) {
    char hexdecnum[100];
    int i = 0;

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexdecnum[i] = remainder + 48;
        }
        else {
            hexdecnum[i] = remainder + 55;
        }
        decimalNumber = decimalNumber / 16;
        i++;
    }

    printf("in hex: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexdecnum[j]);
    }
}

int main() {
    int decimalNumber = 7143;
    decToHex(decimalNumber);

    return 0;
}
