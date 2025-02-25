/* 25.02.2025 307ИС-22 ЛБ */
#include <stdio.h>
#include <string.h>
#define MAX_LINE 100

void sortStrByLen(char arr[][100], int n);

int main() {
    char arr[][MAX_LINE] = {
        "banana",
        "apple",
        "orange"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив строк:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    sortStrByLen(arr, n);

    printf("\nОтсортированный массив строк по длине:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    sortStringsAlphabetically(arr, n);

    printf("\nОтсортированный массив строк по алфавиту:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

	return 0;
}

void sortStrByLen(char arr[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(arr[j]) > strlen(arr[j + 1])) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

void sortStrAlph(char arr[][100], int n) {
    char temp[100]; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}