# Функции <a name="functions"></a>
Функции не являются объектами, но тоже имеют тип.  
Тип функции характеризуется как ее возвращаемым значением, так и числом и типами ее параметров.  

Параметры — это объекты, которые объявляются вместе с функцией и получают значения при входе в нее.  
Аргументы — это выражения, разделяемые запятыми, которые указываются в выражении вызова функции.  

Передача аргументов при вызове происходит по значению; то есть когда вы предоставляете функции аргумент, его значение копируется в отдельную переменную, доступную для использования внутри этой функции.  

## Передача аргументов по значению
```c
#include <stdio.h>
#include <stdlib.h>

void swap(int, int);

int main(void){
    int a = 21, b = 17;

    printf("main: a = %d, b = %d\n", a, b); // main: a = 21, b = 17
    swap(a, b);                             // swap: a = 17, b = 21
    printf("main: a = %d, b = %d\n", a, b); // main: a = 21, b = 17

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

void swap(int*, int*);

int main(void){
    int a = 21, b = 17;

    printf("main: a = %d, b = %d\n", a, b); // main: a = 21, b = 17
    swap(&a, &b);                           // swap: a = 17, b = 21
    printf("main: a = %d, b = %d\n", a, b); // main: a = 17, b = 21

    return EXIT_SUCCESS;
}

void swap(int *pa, int *pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;
    printf("swap: a = %d, b = %d\n", *pa, *pb);
}
```
