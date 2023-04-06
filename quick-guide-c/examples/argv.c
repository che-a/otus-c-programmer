#include <stdio.h>

int main (int argc, char * argv[]) {

    for(int i = 0 ; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    if(argc == 1) {
        printf("Command line has no additional arguments\n");
    }
    return 0;
}
