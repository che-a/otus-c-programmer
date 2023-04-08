#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int n = 27;
    printf("Форматы представления чисел:\n");
    printf("- DEC: %d\n", n);                         // - DEC: 27
    printf("- OCT: %o, %#o\n", n, n);                 // - OCT: 33, 033
    printf("- HEX: %x, %X, %#x, %#X\n", n, n, n, n);  // - HEX: 1b, 1B, 0x1b, 0X1B

    return EXIT_SUCCESS;
}
