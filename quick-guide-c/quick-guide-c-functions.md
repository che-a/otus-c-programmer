## Передача аргументов по значению
```c
#include <stdio.h>
#include <stdlib.h>

/*
    Передача аргументов по значению
*/

void swap(int, int);

int main(void){
    int a = 21;
    int b = 17;

    printf("main: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("main: a = %d, b = %d\n", a, b);

    return EXIT_SUCCESS;
}

void swap(int a, int b){
    int t = a;
    a = b;
    b = t;
    printf("swap: a = %d, b = %d\n", a, b);
}
```

## Имитация передачи аргументов по ссылке
```c
#include <stdio.h>
#include <stdlib.h>

/*
    Имитация передачи аргументов по ссылке
*/

void swap(int*, int*);

int main(void){
    int a = 21;
    int b = 17;

    printf("main: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("main: a = %d, b = %d\n", a, b);

    return EXIT_SUCCESS;
}

void swap(int *pa, int *pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;
    printf("swap: a = %d, b = %d\n", *pa, *pb);
}

```
