#ifndef AIRPLANE_H
#define AIRPLANE_H

#define MAX_FLIGHTS 12
#define MAX_STR_LEN 50

typedef struct {
    int flight_number;
    char departure_time[6];
    char arrival_time[6];
    char destination[MAX_STR_LEN];
    char aircraft_model[MAX_STR_LEN];
    float distance;
} AIRPLANE;

void input_flights(AIRPLANE flights[], int *count);
void find_max_duration(AIRPLANE flights[], int count);
void search_by_destination(AIRPLANE flights[], int count, char *dest);
float average_distance(AIRPLANE flights[], int count);
void count_by_model(AIRPLANE flights[], int count);

#endif
