/*
    Каркас приложения, в котором используется разбор коротких и длинных
    аргументов командной строки.

    struct option{
        const char *name;   // Имя опции без двойного дефиса;

        int has_arg;// Имеет ли длинная опция аргумент:
                    //   0 — не принимает аргумент;
                    //   1 — обязательный аргумент;
                    //   2 — необязательный аргумент.

        int *flag;  // Если этот указатель равен NULL, то getopt_long()
                    // возвращает значение поля val, иначе она
                    // возвращает 0, а переменная на которую указывает
                    // flag заполняется значением val;

        int val;    // Обычно содержит некоторую символьную константу, если
                    // длинная опция соответствует короткой, то эта константа
                    // должна быть такой же как и та что появляется в аргументе
                    // optstring.

        // Важно заметить, что последний элемент массива longopts,
        // должен быть заполнен нулями.

    }
*/
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define VERSION_MAJOR 5
#define VERSION_MINOR 4
#define VERSION_PATCH 27
#define AUTHOR "Автор программы"
#define ABOUT "Каркас программы с разбором аргументов."


void argument_help(char *name);
void argument_version(void);

int main (int argc, char *argv[]){
    int c;
    while (1){
        static struct option long_opt[] = {
            {"input-file", 1, 0, 'i'},
            {"output-file", 1, 0, 'o'},
            {"help", 0, 0, 'h'},
            {"version", 0, 0, 'v'},
            {0,0,0,0}
        };

        int optIdx;
        if((c = getopt_long(argc, argv, "i:o:hv", long_opt, &optIdx)) == -1){
            //printf("Пустой вызов программы!\n");
            break;
        }
        switch(c){
            case 'i':
                printf("option 'c' selected, filename: %s\n", optarg);
                return(1);
            case 'v':
                argument_version();
                return EXIT_SUCCESS;
            case 'h':
            default:
                argument_help(argv[0]);
                return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}

void argument_help(char *name){
    printf("usage: %s\n", name);
    return;
}

void argument_version(void){
    printf("Описание: %s\n", ABOUT);
    printf("Версия:   %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    printf("Автор:    %s\n", AUTHOR);
    return;
}

