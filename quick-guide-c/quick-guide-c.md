# Краткое руководство по языку `C`
### Содержание
* [Функция `main`](#main_function)
* [Объекты](#objects)
* [Типы данных](#types)  
* [Функции](#functions)
* [Указатели](#pointers)


## Функция `main` <a name="main_function"></a>

Функция `main` вызывается при запуске программы. Это главная точка входа программы, которая выполняется в серверной среде, когда программа запускается из командной строки или другой программы.  
Язык `C` имеет две потенциальные среды выполнения:  
- минимальную (freestanding), которая может существовать вне ОС и обычно используется в программировании встраиваемых систем. Такие среды предоставляют минимальный набор библиотечных функций, а название и тип точки входа, которая вызывается при запуске программы, зависит от реализации.
- полноценную (hosted).  



  
  


## Объекты <a name="objects"></a>
Объект — это хранилище, в котором можно представлять значения.  
В стандарте C (ISO/IEC 9899:2018) объектом называется «область хранилища данных в среде выполнения, содержимое которого может представлять значения» с примечанием: «при обращении к объекту можно считать, что он обладает определенным типом».  
Один из примеров объекта — переменная. 


## Функции <a name="functions"></a>
Функции не являются объектами, но тоже имеют тип.
Тип функции характеризуется как ее возвращаемым значением, так и числом и типами ее параметров.

Параметры — это объекты, которые объявляются вместе с функцией и получают значения при входе в нее.
Аргументы — это выражения, разделяемые запятыми, которые указываются в выражении вызова функции.

Передача аргументов при вызове происходит по значению; то есть когда вы предоставляете функции аргумент, его значение копируется в отдельную переменную, доступную для использования внутри этой функции.



## Объявление переменных
```c
char *src;    // src имеет тип char *
char c;       // c имеет тип char
int x;        // x имеет тип int
int y[5];     // y — это массив из 5 элементов типа int
int n[15][3]; // n — это массив из 15 массивов, состоящих из трех элементов типа int
```
У каждого объекта есть срок хранения, который определяет его время жизни (lifetime) — период выполнения программы, на протяжении которого этот объект существует, где-то хранится, имеет постоянный адрес и сохраняет последнее присвоенное ему значение. К объектам нельзя обращаться вне данного периода.

Локальные переменные, такие как `a` и `b` из листинга ниже, имеют автоматический срок хранения (storage duration); то есть они существуют, пока поток выполнения не покинет блок, в котором они определены. 
```c
#include <stdio.h>

int main(void) {
    int a = 21;
    int b = 17;
}
```
## Область видимости

Объекты, функции, макросы и другие идентификаторы имеют область видимости, которая определяет, где к ним можно обращаться. Область видимости может охватывать:
- файл (если объявление сделано за пределами какого-либо блока или списка параметров, то идентификатор доступен на уровне файла; это значит, что область видимости охватывает весь файл, в котором он находится, а также любые другие файлы, подключенные после его объявления),
- блок (если объявление происходит внутри блока или списка параметров, то оно имеет блочную область видимости; то есть объявленный им идентификатор доступен только внутри этого блока),
- прототип функции,
- саму функцию.