#ifndef CITY_MANAGEMENT_H
#define CITY_MANAGEMENT_H

#define MAX_CITY_NAME_LENGTH 50

// City structure
typedef struct {
    char name[MAX_CITY_NAME_LENGTH];
    int index;
} City;

// Function declarations
void add_city();
void display_cities();
void remove_city();
void rename_city();

#endif
