#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#define AR_LEN 1000
#define MAX_NAME_LEN 100
#define MAX_LINE 1024

typedef struct {
    int year;
    int month;
    int day;
} TDate;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    TDate date;
    unsigned short achievement;
} TEvent;

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int is_valid_date(TDate date) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (date.year < 1900 || date.year > 2100) return 0;
    
    if (date.month < 1 || date.month > 12) return 0;
    
    if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)) {
        days_in_month[1] = 29;
    }
    
    if (date.day < 1 || date.day > days_in_month[date.month - 1]) return 0;
    
    return 1;
}

void date_print(TDate d) {
    printf("%02d.%02d.%04d", d.day, d.month, d.year);
}

void event_print(TEvent e) {
    printf("ID: %d\nИмя: %s\nДата: ", e.id, e.name);
    date_print(e.date);
    printf("\nДостижение: %hu\n", e.achievement);
    printf("------------------------\n");
}

void ar_print(TEvent ar[], int n) {
    if (n == 0) {
        printf("Массив пуст!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        event_print(ar[i]);
    }
}

void find_by_name(TEvent ar[], int count, const char* search_name) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(ar[i].name, search_name) != NULL) {
            event_print(ar[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("События с именем, содержащим '%s', не найдены.\n", search_name);
    }
}

// void save_to_file(TEvent ar[], int count, const char* filename) {
//     FILE* file = fopen(filename, "w");
//     if (!file) {
//         printf("Ошибка открытия файла для записи!\n");
//         return;
//     }
// }

int main() {
    char *locale = setlocale(LC_ALL, "ru_RU.UTF-8");

    TEvent ar[AR_LEN];
    int count = 0;
    int choice;
    char search_name[MAX_NAME_LEN];
    char filename[] = "events.txt";

    while (1) {
        printf("\nМеню:\n");
        printf("0. Выход\n");
        printf("1. Добавить событие\n");
        printf("2. Печать массива\n");
        printf("3. Поиск по имени\n");
        printf("4. О программе\n");
        printf("Выберите пункт: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода! Введите число.\n");
            clear_input();
            continue;
        }
        clear_input();

        switch (choice) {
            case 0:
                // printf("Сохранить изменения перед выходом? (1 - да, 0 - нет): ");
                // int save_choice;
                // scanf("%d", &save_choice);
                // if (save_choice == 1) {
                //     save_to_file(ar, count, filename);
                // }
                printf("Спасибо за работу! До свидания.\n");
                return 0;

            case 1: {
                if (count >= AR_LEN) {
                    printf("Массив полон!\n");
                    break;
                }
                TEvent newEvent;

                printf("Введите ID: ");
                if (scanf("%d", &newEvent.id) != 1) {
                    printf("Ошибка ввода ID!\n");
                    clear_input();
                    break;
                }

                printf("Введите имя: ");
                clear_input();
                if (fgets(newEvent.name, MAX_NAME_LEN, stdin) == NULL) {
                    printf("Ошибка ввода имени!\n");
                    break;
                }
                newEvent.name[strcspn(newEvent.name, "\n")] = 0;

                do {
                    printf("Введите дату (день месяц год): ");
                    if (scanf("%d %d %d", &newEvent.date.day, &newEvent.date.month, &newEvent.date.year) != 3) {
                        printf("Ошибка ввода даты!\n");
                        clear_input();
                        continue;
                    }
                } while (!is_valid_date(newEvent.date));

                printf("Введите достижение: ");
                if (scanf("%hu", &newEvent.achievement) != 1) {
                    printf("Ошибка ввода достижения!\n");
                    clear_input();
                    break;
                }

                ar[count++] = newEvent;
                printf("Событие добавлено!\n");
                break;
            }

            case 2:
                ar_print(ar, count);
                break;

            case 3:
                printf("Введите имя для поиска: ");
                if (fgets(search_name, MAX_NAME_LEN, stdin) != NULL) {
                    search_name[strcspn(search_name, "\n")] = 0;
                    find_by_name(ar, count, search_name);
                }
                break;

            case 4:
                printf("Программа для работы с событиями\n");
                printf("Версия 2.0\n");
                printf("Автор: ...\n");
                printf("Возможности:\n");
                printf("- Добавление событий\n");
                printf("- Поиск по имени\n");
                printf("- Сохранение/загрузка данных\n");
                printf("- Валидация введенных данных\n");
                break;

            default:
                printf("Неверный выбор!\n");
        }
    }

    return 0;
}
