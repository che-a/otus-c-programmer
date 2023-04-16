/*
    Каркас приложения, в котором используется разбор коротких и длинных
    аргументов командной строки.
*/
#include <stdbool.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG_MODE_ON 1
#define VERSION_MAJOR 5
#define VERSION_MINOR 4
#define VERSION_PATCH 0
#define AUTHOR "Х.Моржов"
#define ABOUT_PROGRAM "Каркас программы с разбором коротких и длинных аргументов."


void cli_argument_help(char *name);
void cli_argument_version(void);


int main (int argc, char *argv[]){
    if(DEBUG_MODE_ON){
        printf("==> DEBUG: Аргументы командной строки\n");
        for(int i = 0; i < argc; i++){
            printf("%s\n", argv[i]);
        }

    }


    // Аргументы командной строки
    char *city = NULL;
    char *input_file = NULL;
    char *output_file = NULL;
    int  koef = 1;
    bool flag_output_json = false;
    bool flag_help = false;
    bool flag_version = false;


    const char *short_options = "c:i:o:k:jvh";
    /*
     * struct option{
     *     const char *name;   // Имя опции без двойного дефиса;
     *   int has_arg;    // 0 — опция не имеет аргумента;
     *                   // 1 — опция имеет обязательный аргумент;
     *                   // 2 — опция имеет необязательный аргумент.
     *   int *flag;  // flag задает указатель на флаг, в который помещается
     *               // значение val, если найден данный параметр (сама
     *               // функция при этом возвращает 0). Если указатель равен
     *               // NULL, то функция возвращает значение val в качестве результата работы.
     *   int val;        // Поле var содержит значение, которое помещается во
     *                   // flag или возвращается в качестве результата работы функции.
     *}
    */
    const struct option long_options[] = {
        {"city",        1, NULL, 'c'},
        {"input-file",  1, NULL, 'i'},
        {"output-file", 1, NULL, 'o'},
        {"koef",        1, NULL, 'k'},
        {"output-json", 0, NULL, 'j'},
        {"version",     0, NULL, 'v'},
        {"help",        0, NULL, 'h'},
        {NULL,          0, NULL, 0}
    };

    int option_short_name;
    int optIdx;
    opterr = 0;

    // Возвращется буква названия параметра, а если параметры кончились, то функция возвращает -1
    while((option_short_name = getopt_long(argc, argv, short_options, long_options, &optIdx)) != -1){

        if(DEBUG_MODE_ON){
            printf("==> DEBUG:option_short_name\n   %c\n", option_short_name);
        }

        if(option_short_name == '?'){
            printf("Ошибка! Неверные аргументы.\n");
            return EXIT_FAILURE;
        }

        //printf("\nDEBUG: символ=%c код=%d\n", option_short_name, option_short_name);

        printf("=> DEBUG:optarg\n   %s\n", optarg);
        //printf("Ошибка! Нет аргумента у опции.\n");

        switch(option_short_name){
            case 'c': city = optarg; break;
            case 'i': input_file = optarg; break;
            case 'o': output_file = optarg; break;
            case 'k': koef = atoi(optarg); break;
            case 'j': flag_output_json = true; break;
            case 'v': flag_version = true; break;
            case 'h': flag_help = true; break;
        }
    } //while

    if(DEBUG_MODE_ON){
        printf("==> DEBUG:Значения переменных\n");
        printf("    VALUE city:        %s\n", city);
        printf("    VALUE input-file:  %s\n", input_file);
        printf("    VALUE output-file: %s\n", output_file);
        printf("    VALUE koef:        %d\n", koef);
        printf("    FLAG  output-json: %d\n", flag_output_json);
        printf("    FLAG  version:     %d\n", flag_version);
        printf("    FLAG  help:        %d\n", flag_help);
    }
    return EXIT_SUCCESS;
}


void cli_argument_help(char *name){
    printf("%s\n", ABOUT_PROGRAM);
    printf("Использование: %s [ОПЦИИ|-h|-v] \n", name);
    printf("ОПЦИИ:\n"
           "  -c, --city ГОРОД     название города или код места.\n"
           "  -i, --input-file     входящий файл.\n"
           "  -o, --output-file    выходящий файл.\n"
           "  -j, --output-json    вывод прогноза в формате JSON.\n"
           "  -k, --koef           коэффициент.\n"
           "  -h, --help           показать эту справку.\n"
           "  -v, --version        показать информацию о версии.\n"
    );
    return;
}


void cli_argument_version(void){
    printf("Описание: %s\n", ABOUT_PROGRAM);
    printf("Версия:   %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    printf("Автор:    %s\n", AUTHOR);
    return;
}
