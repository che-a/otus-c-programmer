#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    printf("basename: %s\n", argv[0]);

    for(int i = 1; i < argc; i++) {
        printf("Arg %d: %s\n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}
