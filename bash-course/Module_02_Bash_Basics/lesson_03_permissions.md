# Урок 3: Права доступа в Bash

## Введение в права доступа

В операционных системах на базе Unix, включая Linux, права доступа определяют, кто может читать, записывать или выполнять файлы и директории. Понимание прав доступа является важной частью работы с Bash, так как это позволяет управлять безопасностью и доступом к ресурсам системы.

## Типы прав доступа

Существует три основных типа прав доступа:

1. **Чтение (r)**: Позволяет просматривать содержимое файла или директории.
2. **Запись (w)**: Позволяет изменять содержимое файла или добавлять/удалять файлы в директории.
3. **Выполнение (x)**: Позволяет выполнять файл как программу или скрипт.

## Уровни доступа

Права доступа могут быть назначены для трех категорий пользователей:

- **Владелец (user)**: Пользователь, который создал файл.
- **Группа (group)**: Группа пользователей, к которой принадлежит владелец файла.
- **Другие (others)**: Все остальные пользователи.

## Просмотр прав доступа

Чтобы просмотреть права доступа к файлу или директории, используйте команду `ls -l`. Например:

```bash
ls -l имя_файла
```

Вывод будет выглядеть примерно так:

```
-rwxr-xr-- 1 user group 0 Oct  1 12:00 имя_файла
```

Здесь:

- `-rwxr-xr--` — права доступа.
- `1` — количество жестких ссылок.
- `user` — владелец файла.
- `group` — группа владельца.
- `0` — размер файла в байтах.
- `Oct 1 12:00` — дата и время последнего изменения.
- `имя_файла` — имя файла.

## Изменение прав доступа

Для изменения прав доступа используется команда `chmod`. Синтаксис команды:

```bash
chmod [опции] права имя_файла
```

### Примеры использования `chmod`

1. Чтобы добавить право на выполнение для владельца:

```bash
chmod u+x имя_файла
```

2. Чтобы удалить право на запись для группы:

```bash
chmod g-w имя_файла
```

3. Чтобы установить права доступа для всех пользователей:

```bash
chmod a+r имя_файла
```

## Заключение

Понимание и управление правами доступа в Bash — это ключевой аспект работы с файлами и директориями. Это знание поможет вам обеспечить безопасность ваших данных и управлять доступом к ресурсам системы.

## Задание

1. Создайте файл и измените его права доступа, чтобы только вы могли его читать и записывать.
2. Попробуйте изменить права доступа для группы и других пользователей, чтобы они могли только читать файл.
3. Используйте команду `ls -l`, чтобы проверить изменения прав доступа.