#include <stdio.h>
#include "airplane.h"

int main(void) {
    AIRPLANE flights[MAX_FLIGHTS];
    int count = 0;
    char dest[MAX_STR_LEN];
    
    printf("=== Программа учёта авиарейсов ===\n");
    
    input_flights(flights, &count);
    find_max_duration(flights, count);
    
    printf("\nВведите направление для поиска: ");
    scanf("%s", dest);
    search_by_destination(flights, count, dest);
    
    float avg = average_distance(flights, count);
    printf("\nСреднее расстояние всех рейсов: %.2f км\n", avg);
    
    count_by_model(flights, count);
    
    return 0;
}
