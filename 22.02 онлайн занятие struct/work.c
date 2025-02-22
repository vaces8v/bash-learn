#include <stdio.h>

struct Product {
    int code;
    char name[50];
    float cost;
    int quantity;
};

struct TotalCost {
    int code; 
    float total;
};

int main() {
    struct Product products[100];  
    struct TotalCost totals[50]; 
    int prod_count = 0;
    int total_count = 0;

    printf("Введите данные в формате: |шифр| |название| |затраты| |количество|\n");

    while (scanf("%d %s %f %d", 
           &products[prod_count].code,
           products[prod_count].name,
           &products[prod_count].cost,
           &products[prod_count].quantity) == 4) {
        prod_count++;
    }

    for (int i=0; i < prod_count; i++ ) {
        int found = 0;
        float item_total = products[i].cost * products[i].quantity;

        for (int j=0; j < total_count; j++) {
            if(totals[i].code == products[i].code) {
                totals[j].total += item_total;
                found = 1;
                break;
            }
        }

        if(!found) {
            totals[total_count].code = products[i].code;
            totals[total_count].total = item_total;
            total_count++;
        }
    }


    for (int i=0; i < total_count; i++) {
        for (int j=0; j < total_count - i- 1; j++) {
            if(totals[j].code > totals[j + 1].code) {
                struct TotalCost temp = totals[i];
                totals[j] = totals[j + 1];
                totals[j + 1] = temp;
            }
        }
    }

    return 0;
}