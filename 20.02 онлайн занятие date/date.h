#ifndef MY_DATE_H
#define MY_DATE_H

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

void get_date_from_str(const char* str, Date* d);
void get_year_from_str(const char* str, int* d);
void get_month_from_str(const char* str, int* d);
void get_day_from_str(const char* str, int* d);
int are_dates_equal(const Date* d1, const Date* d2);
void increase_date(Date* d);
Date get_max_date(const Date dates[], int size);
void sort_dates(Date dates[], int size);

#endif