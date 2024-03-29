# Занятие 4. Типы данных (продолжение) 
- [Домашнее задание](#homework)
  - [Постановка задачи](#statement)
  - [Выполнение](#completion)
    - [Описание предметной области](#subject_area)


## Домашнее задание <a name="homework"></a>
### Постановка задачи <a name="statement"></a>
**Сложность**: 1/5  
**Условие**: Написать конвертер из заданной кодировки (одна из `CP-1251`, `KOI8-R`, `ISO-8859-5`) в `UTF-8`.  
**Требования**:  
<!-- TODO-IST:START -->
* [x] Сторонние библиотеки, включая `iconv`, не использовать.  
* [ ] Создано консольное приложение, принимающее аргументами командной строки входной файл, заданную кодировку и выходной файл.
* [ ] Конвертация из каждой из трёх указанных кодировок корректно отрабатывает (файлы для проверки прилагаются).
* [ ] Приложение корректно обрабатывает ошибки доступа к файлам.
* [ ] Код компилируется без предупреждений с ключами компилятора `-Wall` `-Wextra` `-Wpedantic` `-std=c11`.
* [ ] Далее успешность определяется ревью кода.
<!-- TODO-IST:END -->

### Выполнение <a name="completion"></a>
#### Описание предметной области <a name="subject_area"></a>
`Unicode` — это не кодировка, а именно таблица символов, которая состоит из 1 114 112 позиций. Большинство этих позиций пока не заполнены символами.  

Разделено это общее пространство на 17 блоков, по 65 536 символов в каждом. Каждый блок содержит свою группу символов. Нулевой блок — базовый, там собраны наиболее употребляемые символы всех современных алфавитов. Во втором блоке находятся символы вымерших языков. Есть два блока отведенные под частное использование. Большинство блоков пока не заполнены.  

Итого емкость символов юникода составляет от 0 до 10FFFF (в шестнадцатиричном виде).  

Записываются символы в шестнадцатиричном виде с приставкой «U+». Например первый базовый блок включает в себя символы от U+0000 до U+FFFF (от 0 до 65 535), а последний семнадцатый блок от U+100000 до U+10FFFF (от 1 048 576 до 1 114 111).  
