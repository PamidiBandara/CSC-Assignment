#ifndef CITY_MANAGEMENT_H
#define CITY_MANAGEMENT_H

#define MAX_CITY_NAME_LENGTH 50
#define MAX_CITIES 30

typedef struct {
    char name[MAX_CITY_NAME_LENGTH];
    int index;
} City;
typedef struct {
    City cities[MAX_CITIES];
    int cityCount;
}
CitySystem;

void initialize_city_system(CitySystem*system);
void add_city(CitySystem*system);
void display_cities(CitySystem*system);
void remove_city(CitySystem*system);
void rename_city(CitySystem*system);
void city_management_menu(CitySystem*system);


#endif
