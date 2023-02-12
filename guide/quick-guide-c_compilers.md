
## Компиляторы
### GNU Compiler Collection
[gcc](https://gcc.gnu.org/)
```sh
apt-get install gcc
gcc --version
```
#### Компиляция и запуск
```sh
cc hello.c
./a.out

# Другой вариант
cc -o hello hello.c
./hello

# Другой вариант
cc -Wall -Wextra -Wpedantic -std=c11 -o main main.c 
```


### Clang
[clang](https://clang.llvm.org/)
```sh
apt-get install clang
clang --version
```
