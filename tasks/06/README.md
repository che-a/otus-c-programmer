# 6. Современные правктики программирования на C

## Рекомендации по семантике
### Ссылки га документы по лучшим практикам
* [SEI CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard) — хороший набор рекомендаций (бесплатный).
* [MISRA C](https://misra.org.uk) — довольно распространенный набор рекомендаций (платный) из автомобильной индустрии.
* [NASA C style guide](https://ntrs.nasa.gov/api/citations/19950022400/downloads/19950022400.pdf), [Mars Code](https://cacm.acm.org/magazines/2014/2/171689-mars-code/fulltext) — наборы рекомендаций, которые интересны прежде всего с исторической точки зрения.
* [Micriµm C Coding Standard](https://d1.amobbs.com/bbs_upload782111/files_38/ourdev_630682QLHUQ2.pdf) — широко известный в узких кругах набор рекомендаций от фирмы-производителя ПО для маломощных процессоров.
* [Steve Oualline. C Elements of Style: The Programmer's Style Manual for Elegant C and C++ Programs](http://www.oualline.com/books.free/style/index.html) — представляет исторический интерес.
* [Марсокод, или Как создавалось ПО для марсохода Curiosity](https://devby.io/news/marsokod-ili-kak-sozdavalos-po-dlya-marsohoda-curiosity)
* [49 Атрибутов хорошего С-кода](https://habr.com/ru/post/679256)

### Ссылки на документы по наихудшим практикам
* "C с классами". [Orthodox C++](https://gist.github.com/bkaradzic/2e39896bc7d8c34e042b) — написание программ на C++, но с использование только возможностей языка C.

## Рекомендации по стилистике
* [Linux kernel coding style](https://www.kernel.org/doc/html/v4.19/process/coding-style.html)
  * [Kernel Coding the Upstream Way - Tim Bird, Sony](https://youtu.be/dApfkuObBW8)
* [OpenSSL coding style](https://openssl.org/policies/technical/coding-style.html)
* [FreeBSD kernel style guide](https://freebsd.org/cgi/man.cgi?query=style&sektion=9)
* [GNU coding standards](https://gnu.org/prep/standards/standards.html#Writing-C)
* [Apache Developers' C Language Style Guide](https://httpd.apache.org/dev/styleguide.html)
* [OpenResty C Coding Style Guide](https://openresty.org/en/c-coding-style-guide.html), [ngx-releng](https://github.com/openresty/openresty-devel-utils/blob/master/ngx-releng)

### Автоматические форматтеры кода
* [GNU indent](https://gnu.org/software/indent/manual/indent.html) — очень старый инструмент, но ингода еще используется.
* [Uncrustify](http://uncrustify.sourceforge.net)
  * [UncrustifyConfig](https://cdanu.github.io/uncrustify_config_preview/index.html) — веб инструмент.
* [clang-format](https://clang.llvm.org/docs/ClangFormat.html)
  * [clang-format configurator](https://zed0.co.uk/clang-format-configurator) — веб инструмент.

## Лучшие практики
### Избегание неопределенного поведения (undefined behavior)
