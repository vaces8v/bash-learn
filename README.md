# Заметки по Bash
> *Здесь я буду выписывать и описывать все, что выучил по оболочке bash*

## 1. Переменные 
В Bash переменные создаются без указания типа. При присваивании значения важно не оставлять пробелы вокруг знака `=`:

```bash
name="John"           # правильно
age=25               # правильно
city = "Moscow"      # неправильно!
```

Для использования значения переменной, нужно добавить `$` перед именем:
```bash
echo $name          # выведет John
echo "${name}"      # тоже выведет John, но более безопасный способ
```

## 2. Шебанг
Шебанг помогает понять оболочке как запустить файл, обычно указываестя вверху файла и пишется так:
```bash
#!/bin/bash
```
Можно указывать и по другому путь. В интернете часто спорят и считают, что `#!/bin/bash` не считается надежным и предлагают писать шебанг таким образом:
```bash
#!/usr/bin/env bash
```
Однако, и не такой путь всегда совместим и может приводить к ошибкам, но считается более надежным.

## 3. Предсказуемые ошибки
Bash при выполнении скрипта игнорирует ошибки и продолжает выполнять код, из-за этого поведение становится не предсказуемым. В языках высокого уровня по типу Python, C++, JavaScript ошибки приводят к выходу программы, если мы их не обрабатываем. Но мы можем настроить нашу оболочку так, чтобы ошибки в наших скриптах были более предсказуемыми используая команду:
```bash
set -Eeuo pipefail
```
Разберем, что выполняет каждая команда:
1. `set` устанавливает настройки оболочки
2. Параметр `-E` выдает болле явные ошибки для команды `trap`
3. `e` дает более предсказуемое поведение команд с ошибками
4. `u` выдает ошибку если мы используем не сушествующую переменную
5. `o` параметр, который дает возможность перечислять настройки после параметра `-o pipefail` или `-o extraerror`

## 4. Исполнение команд
В Bash есть несколько способов выполнить команду и сохранить её вывод:

```bash
output=$(ls -l)     # современный способ
output=`ls -l`      # старый способ (обратные кавычки)
```

Команды можно объединять с помощью операторов:
```bash
command1 && command2  # command2 выполнится только если command1 успешна
command1 || command2  # command2 выполнится только если command1 неуспешна
command1 ; command2   # выполнить обе команды независимо от результата
```

## 5. Ветвления 
Условные конструкции в Bash:

```bash
if [ "$name" = "John" ]; then
    echo "Hello John!"
elif [ "$name" = "Jane" ]; then
    echo "Hello Jane!"
else
    echo "Hello stranger!"
fi

# Case statement
case "$name" in
    "John")
        echo "Hello John!"
        ;;
    "Jane")
        echo "Hello Jane!"
        ;;
    *)
        echo "Hello stranger!"
        ;;
esac
```

## 6. Циклы
Bash поддерживает несколько типов циклов:

```bash
# For loop
for i in 1 2 3 4 5; do
    echo $i
done

# While loop
count=1
while [ $count -le 5 ]; do
    echo $count
    ((count++))
done

# Until loop
count=1
until [ $count -gt 5 ]; do
    echo $count
    ((count++))
done
```

## 7. Функции
Функции в Bash объявляются следующим образом:

```bash
function greeting() {
    echo "Hello, $1!"  # $1 - первый аргумент функции
}

# Или более короткая запись
say_bye() {
    echo "Goodbye, $1!"
}

# Вызов функций
greeting "John"
say_bye "John"
```

## 8. Математические операции
В Bash есть несколько способов выполнять математические операции:

```bash
# Использование let
let "a = 5 + 4"

# Использование ((..))
((b = 5 + 4))

# Использование expr
c=$(expr 5 + 4)

# Использование $((..))
d=$((5 + 4))
```

## 9. Проверка файлов
Bash предоставляет множество операторов для проверки файлов:

```bash
if [ -f "file.txt" ]; then    # существует ли файл
    echo "File exists"
fi

if [ -d "dir" ]; then         # существует ли директория
    echo "Directory exists"
fi

if [ -r "file.txt" ]; then    # можно ли читать файл
    echo "File is readable"
fi

if [ -w "file.txt" ]; then    # можно ли писать в файл
    echo "File is writable"
fi
```

## 10. Параметры и shift
Скрипты Bash могут принимать параметры командной строки:

```bash
#!/bin/bash
echo "Первый параметр: $1"
echo "Второй параметр: $2"
echo "Все параметры: $@"
echo "Количество параметров: $#"

# Сдвиг параметров
shift
echo "После shift, первый параметр: $1"
```

## Простая cli-утилита
Пример простой утилиты командной строки:

```bash
#!/bin/bash
set -Eeuo pipefail

function show_help() {
    echo "Использование: $0 [-h] [-n NAME]"
    echo "Опции:"
    echo "  -h     Справочник"
    echo "  -n     Указать имя"
}

name=""

while getopts "hn:" opt; do
    case $opt in
        h)
            show_help
            exit 0
            ;;
        n)
            name=$OPTARG
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
    esac
done

if [ -z "$name" ]; then
    echo "Ошибка: имя обязательно" >&2
    show_help
    exit 1
fi

echo "Привет, $name!"
```

## 11. Дескрипторы 
В Bash есть три стандартных дескриптора:
- 0: stdin (стандартный ввод)
- 1: stdout (стандартный вывод)
- 2: stderr (стандартный вывод ошибок)

## 12. Перенаправления потока данных
Bash позволяет перенаправлять потоки данных:

```bash
command > output.txt     # перенаправление stdout в файл
command 2> error.txt     # перенаправление stderr в файл
command &> all.txt       # перенаправление stdout и stderr в файл
command < input.txt      # чтение stdin из файла
```

## 13. Сигналы
Bash может обрабатывать системные сигналы:

```bash
# Обработка сигнала SIGINT (Ctrl+C)
trap 'echo "Получен сигнал SIGINT"; exit 1' SIGINT

# Обработка сигнала EXIT
trap 'echo "Скрипт завершается"' EXIT

# Игнорирование сигнала SIGTERM
trap '' SIGTERM
