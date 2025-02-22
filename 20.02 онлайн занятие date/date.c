#include <stdio.h>
#include "date.h"

struct date {
	int year;
	int month;
	int day;
};

void get_year_from_str(const char* str, int* d) {
    sscanf(str, "%d.%*d.%*d", d);
}

void get_month_from_str(const char* str, int* d) {
    sscanf(str, "%*d.%d.%*d", d);
}

void get_day_from_str(const char* str, int* d) {
    sscanf(str, "%*d.%*d.%d", d);
}

void get_date_from_str(const char* str, struct date* d) {
    sscanf(str, "%d.%d.%d", &d->year, &d->month, &d->day);
}

int are_dates_equal(const struct date* d1, const struct date* d2) {
    return d1->year == d2->year &&
           d1->month == d2->month &&
           d1->day == d2->day;
}

void increase_date(struct date* d) {
    // Упрощённая реализация без учёта разного количества дней в месяцах
    if (++d->day > 31) {
        d->day = 1;
        if (++d->month > 12) {
            d->month = 1;
            d->year++;
        }
    }
}

struct date get_max_date(const struct date dates[], int size) {
    struct date max = dates[0];
    for (int i = 1; i < size; i++) {
        if (dates[i].year > max.year ||
           (dates[i].year == max.year && dates[i].month > max.month) ||
           (dates[i].year == max.year && dates[i].month == max.month && dates[i].day > max.day)) {
            max = dates[i];
        }
    }
    return max;
}

void sort_dates(struct date dates[], int size) {
    // Простая пузырьковая сортировка
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (dates[j].year > dates[j+1].year ||
               (dates[j].year == dates[j+1].year && dates[j].month > dates[j+1].month) ||
               (dates[j].year == dates[j+1].year && dates[j].month == dates[j+1].month && dates[j].day > dates[j+1].day)) {
                struct date temp = dates[j];
                dates[j] = dates[j+1];
                dates[j+1] = temp;
            }
        }
    }
}
