
## Компиляция
### Содержание
- [Этапы реализация программы на Си](#compile)
- [Реализации компиляторов](#compilers)  

## Этапы реализация программы на Си
- **Обработка препроцессором**. В общем случае компиляторы языка Си выполняют некоторую подготовительную работу над исходным кодом перед компиляцией.
- **Компиляция**. Компилятор преобразовывает исходный код на языке Си в код на машинном языке и помещает его в объектный файл, который еще не готов к запуску на выполнение. В нём не хватает кода запуска (будет отличаться для разных ОС) и кода библиотечных подпрограмм.
- **Компоновка**. Роль компоновщика заключается в сборе вместе трех элементов — объектного кода, стандартного кода запуска для установленной системы и библиотечного кода — и последующем их помещении в отдельный файл, который называется исполняемым.

### Пример
```c
#include <stdio.h>

int main(void){
    printf("Hello, world!");
    return 0;
}
```


## Реализации компиляторов
### GNU Compiler Collection
[Официальный сайт проекта GCC](https://gcc.gnu.org/)
```sh
apt-get install gcc
gcc --version
```
#### Компиляция и запуск
Компиляция файла с исходным кодом на Си `hello.c` в программу `a.out` и её запуск:
```sh
cc hello.c
./a.out
```
Компиляция файла с исходным кодом на Си `hello.c` с указанием имени выходного файла и его запуск:
```sh
cc -o hello hello.c
./hello
```
Компиляция с опциями:
```sh
cc -Wall -Wextra -Wpedantic -std=c11 -o hello hello.c 

# Сборка файла исходного кода snippet.c в исполняемый бинарный файл snippet, обеспечивая выполнение многих предупреждающих проверок, значительных, но разумных оптимизаций, а также отладку. 
gcc -Wall -Wextra -O2 -g -o hello hello.c
```


### Clang
[Официальный сайт проекта Clang](https://clang.llvm.org/)
```sh
apt-get install clang
clang --version
```


## Компиляция
Пример файла Makefile:
```makefile
CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11

BIN=main

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl

clean:
	$(RM) -rf $(BIN) *.dSYM
```

```c
//#include "curl-8.0.1/include/curl/curl.h"
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    CURL *curl = curl_easy_init();
    if(!curl) {
        fprintf(stderr, "Init failed\n");
        return EXIT_FAILURE;
    }
    
    //set options
    curl_easy_setopt(curl, CURLOPT_URL, "https://zbbx-sargp.ru");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);  // Для незащищённых TLS-соединений
    
    // Выполнить действие
    CURLcode result = curl_easy_perform(curl);
    printf("=== DEBUG ===: %d", result);
    
    if (result != CURLE_OK){
        fprintf(stderr, "Download problem: %s\n", curl_easy_strerror(result));
    }
    
    curl_easy_cleanup(curl);    
    return EXIT_SUCCESS;
}

```

```bash
make
make clean
```
