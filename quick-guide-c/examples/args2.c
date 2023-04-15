/*
    Программа...

*/

#include <stdio.h>
#include <string.h>


void arg_help(char * basename);

int main(int argc, char **argv) {
    if(argc <= 1) {
        arg_help(argv[0]);
        return 0;
    }
    if(!strcmp(argv[1], "--help")) {
        printf("You requested help message.\n");
    } else if(!strcmp(argv[1], "--add")) {
        if(argc <= 3) {
            printf("'--add' operation requires two parameters.\n");
        } else {
            int a, b;
            if(sscanf(argv[2], "%d", &a) != 1 || sscanf(argv[3], "%d", &b) != 1) {
                printf("'--add' operation requires two integer parameters.\n");
            } else {
                printf("%d + %d = %d\n", a, b, a+b);
            }
        }
    } else {
        printf("Unknown parameter: '%s'. Type %s --help for help.\n", argv[1], argv[0]);
    }
    return 0;
}

void arg_help(char * basename){
    printf("Использование: %s [ОПЦИИ] \n", basename);
    printf("ОПЦИИ:\n"
           "  -c, --city ГОРОД     название города или код места.\n"
           "  -h, --help           показать эту справку.\n"
           "  -j, --output-json    вывод прогноза в формате JSON.\n"
           "  -v, --version        показать информацию о версии.\n"
    );
}
