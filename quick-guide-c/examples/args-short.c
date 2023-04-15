/*
    Каркас приложения, в котором используется разбор КОРОТКИХ аргументов
    командной строки.
*/
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

const char * str1 = "Каркас приложения, в котором используется разбор КОРОТКИХ аргументов "
                    "командной строки.\n";

void arg_help(char * basename);



int main(int argc, char *argv[]) {

    if(argc == 1) { // если запускаем без аргументов, выводим справку
        arg_help(argv[0]);
        return EXIT_SUCCESS;
    }
    char *opts = "a:b:o:"; // доступные опции, каждая принимает аргумент
    int a, b; // тут храним числа
    char op; // а тут оператор
    int opt; // каждая следующая опция попадает сюда
    while((opt = getopt(argc, argv, opts)) != -1) { // вызываем getopt пока она не вернет -1
         switch(opt) {
             case 'a': // если опция -a, преобразуем строку с аргументом в число
                 a = atoi(optarg);
                 break;
              case 'b': // тоже для -b
                  b = atoi(optarg);
                  break;
              case 'o': // в op сохраняем оператор
                  op = optarg[0];
                  break;
         }
     }
    switch(op) {
        case '+': // если опаратор + складываем, и т.д.
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d — %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, a / b);
            break;
    }
    return EXIT_SUCCESS;
}

void arg_help(char * basename){
    printf("Использование: %s [ОПЦИИ] \n", basename);
    printf("%s", str1);
    printf("ОПЦИИ:\n"
           "  -c, --city ГОРОД     название города или код места.\n"
           "  -h, --help           показать эту справку.\n"
           "  -j, --output-json    вывод прогноза в формате JSON.\n"
           "  -v, --version        показать информацию о версии.\n"
    );
}
