#include <stdio.h>
#include <string.h>
#include "airplane.h"

void input_flights(AIRPLANE flights[], int *count) {
    printf("Введите количество рейсов (макс. %d): ", MAX_FLIGHTS);
    scanf("%d", count);
    
    for (int i = 0; i < *count; i++) {
        printf("\nРейс #%d:\n", i + 1);
        printf("  Номер рейса: ");
        scanf("%d", &flights[i].flight_number);
        printf("  Время вылета (HH:MM): ");
        scanf("%s", flights[i].departure_time);
        printf("  Время прилёта (HH:MM): ");
        scanf("%s", flights[i].arrival_time);
        printf("  Направление: ");
        scanf("%s", flights[i].destination);
        printf("  Марка самолёта: ");
        scanf("%s", flights[i].aircraft_model);
        printf("  Расстояние (км): ");
        scanf("%f", &flights[i].distance);
    }
}

void find_max_duration(AIRPLANE flights[], int count) {
    if (count == 0) return;
    
    int max_idx = 0;
    int max_minutes = 0;
    
    for (int i = 0; i < count; i++) {
        int dep_h, dep_m, arr_h, arr_m;
        sscanf(flights[i].departure_time, "%d:%d", &dep_h, &dep_m);
        sscanf(flights[i].arrival_time, "%d:%d", &arr_h, &arr_m);
        
        int dep_minutes = dep_h * 60 + dep_m;
        int arr_minutes = arr_h * 60 + arr_m;
        int duration = arr_minutes - dep_minutes;
        
        if (duration > max_minutes) {
            max_minutes = duration;
            max_idx = i;
        }
    }
    
    printf("\nРейс с максимальной длительностью:\n");
    printf("  Номер: %d, Направление: %s, Длительность: %d мин\n",
           flights[max_idx].flight_number,
           flights[max_idx].destination,
           max_minutes);
}

void search_by_destination(AIRPLANE flights[], int count, char *dest) {
    printf("\nРейсы в направлении %s:\n", dest);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(flights[i].destination, dest) == 0) {
            printf("  Номер: %d, Время: %s-%s, Самолёт: %s\n",
                   flights[i].flight_number,
                   flights[i].departure_time,
                   flights[i].arrival_time,
                   flights[i].aircraft_model);
            found = 1;
        }
    }
    
    if (!found) {
        printf("  Рейсов не найдено\n");
    }
}

float average_distance(AIRPLANE flights[], int count) {
    if (count == 0) return 0;
    
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += flights[i].distance;
    }
    
    return sum / count;
}

void count_by_model(AIRPLANE flights[], int count) {
    char models[MAX_FLIGHTS][MAX_STR_LEN];
    int counts[MAX_FLIGHTS] = {0};
    int unique_count = 0;
    
    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(flights[i].aircraft_model, models[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            strcpy(models[unique_count], flights[i].aircraft_model);
            counts[unique_count] = 1;
            unique_count++;
        }
    }
    
    printf("\nСтатистика по моделям самолётов:\n");
    for (int i = 0; i < unique_count; i++) {
        printf("  %s: %d рейсов\n", models[i], counts[i]);
    }
}
