/** Структура Дата.
/** Гусятинер Л.Б., КМПО, 307-314-315ИС-22, 20.02.2025.
План на день */
/// 1. Массив дат
/// 2. Функция получения дня, месяца, года
/// 3. Проверка на равенство дат
/// 4. Увеличение даты на 1
/// 5. Получение максимальной даты в массиве
/// 6. Сортировка дат

#include <stdio.h>
#include "date.h"
#define AR_LEN 1000

struct date {
	int year;
	int month;
	int day;
};

int main() {
    // struct date d1;
    // struct date ar[AR_LEN];
    // scanf("%d.%d.%d", &ar[0].year, &ar[0].month, &ar[0].day);
    // printf("this date is %d.%d.%d\n", ar[0].year, ar[0].month, ar[0].day);
    // struct date ar2[AR_LEN] = { {1,2,3} };
    // printf("other date is %d.%d.%d\n", ar2[0].year, ar2[0].month, ar2[0].day);
    // printf("other date is %d.%d.%d\n", ar2[71].year, ar2[71].month, ar2[71].day);


    /// Задание 1
    struct date dates[3] = {
        {2022, 2, 23},
        {2024, 5, 12},
        {2025, 1, 4},
    };

    for (int i = 0; i < 3; i++) {
        printf("%d.%d.%d\n", dates[i].year, dates[i].month, dates[i].day);
    };

    /// Заданеи 2
    const char *date_str = "2023.10.05";
    struct date date2;
    int day2;
    int month2;
    int year2;

    get_date_from_str(date_str, &date2);
    printf("Год: %d\n", date2.year);
    printf("Месяц: %d\n", date2.month);
    printf("День: %d\n", date2.day);

    printf("_______________________________________");

    get_year_from_str(date_str, &year2);
    get_mounth_from_str(date_str, &month2);
    get_day_from_str(date_str, &day2);

    printf("Год отдельный из функции: %d\n", year2);
    printf("Месяц отдельный из функции: %d\n", month2);
    printf("День отдельный из функции: %d\n", day2);

    struct date date3 = {2025, 1, 4};
    struct date date4 = {2025, 1, 4};
    printf("\nДаты равны? %s\n", are_dates_equal(&date3, &date4) ? "Да" : "Нет");

    increase_date(&date3);
    printf("Дата после увеличения: %d.%d.%d\n", date3.year, date3.month, date3.day);

    sort_dates(dates, 3);
    printf("\nОтсортированные даты:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d.%d.%d\n", dates[i].year, dates[i].month, dates[i].day);
    }

	return 0;
}